# flake8: noqa
import sys
import importlib.util


def installation_info() -> None:
    """Display installation instructions for missing dependencies."""
    print("Installing with pip ⬇⬇⬇⬇")
    print("pip install -r requirements.txt\npython3 loading.py")
    print("------------------------------------------------------")
    print("Installing with poetry ⬇⬇⬇⬇")
    print("poetry install\npoetry run python loading.py")


def is_pkg_installed(package_name,  display_name=None) -> tuple[bool, str | None, str]:
    """
    Check if a package is installed and return its version.
    Args:
        package_name: The actual package name to import
        display_name: The display name (defaults to package_name)
    Returns:
        tuple: (is_installed, version, error_message)
    """

    if display_name is None:
        display_name = package_name

    search_package = importlib.util.find_spec(display_name)
    if search_package is None:
        message = f"❌ {display_name} is not installed yet.\n"
        message += f"   Install it with: pip install {package_name}"
        return False, None, message
    try:
        pkg_do = ""
        module = importlib.import_module(package_name)
        version = getattr(module, "__version__", "version unknown")
        if package_name == "pandas":
            pkg_do = "Data manipulation"
        elif package_name == "requests":
            pkg_do = "Network access "
        elif package_name == "matplotlib":
            pkg_do = "Visualization"

        message = f"✅ {display_name} (version {version}) - {pkg_do} "
        message += "Ready to use!"
        return True, version, message
    except ModuleNotFoundError:
        message = f"⚠️ {display_name} is installed but couldn't load.\n"
        message += f"Reinstalling with: pip install --upgrade {package_name}"
        return False, None, message


def check_dependencies() -> dict:

    """
    Check all required dependencies and return status.

    Returns:
        dict: Dependency status information
    """
    print("LOADING STATUS:")
    print("Loading programs...\n")
    print("Checking dependencies:")

    dependencies = {"pandas": is_pkg_installed("pandas", "pandas"),
                    "numpy": is_pkg_installed("numpy", "numpy"),
                    "matplotlib": is_pkg_installed("matplotlib", "matplotlib"),
                    "requests": is_pkg_installed("requests", "requests")
                    }

    all_in = True
    for package, (is_installed, version, message) in dependencies.items():
        print(message)
        if not is_installed and package != 'requests':  # requests is optional
            all_in = False
    print()
    return all_in, dependencies


def generate_matrix_data():
    """
    Generate simulated Matrix data for analysis.

    Returns:
        pandas.DataFrame: Simulated data
    """
    import numpy as np
    import pandas as pd

    np.random.seed(42)  # For reproducibility

    # Simulate Matrix data: response times, success rates, anomalies
    n_points = 1000

    data = {
        'timestamp': pd.date_range('2024-01-01', periods=n_points, freq='1min'),
        'response_time_ms': np.random.exponential(scale=50, size=n_points),
        'success_rate': np.random.beta(a=9, b=1, size=n_points),
        'anomaly_score': np.random.gamma(shape=2, scale=0.5, size=n_points),
        'load_factor': np.random.normal(loc=0.7, scale=0.15, size=n_points),
        'agents_detected': np.random.poisson(lam=2, size=n_points)
    }

    # Clip values to realistic ranges
    data['success_rate'] = np.clip(data['success_rate'], 0, 1)
    data['load_factor'] = np.clip(data['load_factor'], 0, 1)
    
    return pd.DataFrame(data)


def analyze_data(df):
    """
    Perform analysis on the Matrix data.

    Args:
        df: pandas DataFrame with Matrix data

    Returns:
        dict: Analysis results
    """
    import numpy as np

    print("Analyzing Matrix data...")
    print(f"Processing {len(df)} data points...\n")

    results = {
        'total_points': len(df),
        'avg_response_time': df['response_time_ms'].mean(),
        'avg_success_rate': df['success_rate'].mean(),
        'total_anomalies': (df['anomaly_score'] > 2.0).sum(),
        'avg_load': df['load_factor'].mean(),
        'total_agents': df['agents_detected'].sum(),
        'max_response_time': df['response_time_ms'].max(),
        'min_success_rate': df['success_rate'].min()
    }

    # Print summary statistics
    print("ANALYSIS RESULTS:")
    print(f"  Total Data Points: {results['total_points']}")
    print(f"  Average Response Time: {results['avg_response_time']:.2f} ms")
    print(f"  Average Success Rate: {results['avg_success_rate']:.2%}")
    print(f"  Anomalies Detected: {results['total_anomalies']}")
    print(f"  Average System Load: {results['avg_load']:.2%}")
    print(f"  Total Agents Detected: {results['total_agents']}")
    print()

    return results


def create_visualization(df, output_file='matrix_analysis.png'):
    """
    Create visualization of Matrix data.

    Args:
        df: pandas DataFrame with Matrix data
        output_file: Output filename for the plot
    """
    import matplotlib.pyplot as plt

    print("Generating visualization...")

    # Create a 2x2 grid of plots
    fig, axes = plt.subplots(2, 2, figsize=(14, 10))
    fig.suptitle('Matrix System Analysis', fontsize=16, fontweight='bold')

    # Plot 1: Response Time Over Time
    axes[0, 0].plot(df['timestamp'], df['response_time_ms'], 
                    color='green', alpha=0.6, linewidth=0.5)
    axes[0, 0].set_title('Response Time Over Time')
    axes[0, 0].set_xlabel('Timestamp')
    axes[0, 0].set_ylabel('Response Time (ms)')
    axes[0, 0].grid(True, alpha=0.3)
    axes[0, 0].tick_params(axis='x', rotation=45)

    # Plot 2: Success Rate Distribution
    axes[0, 1].hist(df['success_rate'], bins=30, color='blue', 
                    alpha=0.7, edgecolor='black')
    axes[0, 1].set_title('Success Rate Distribution')
    axes[0, 1].set_xlabel('Success Rate')
    axes[0, 1].set_ylabel('Frequency')
    axes[0, 1].grid(True, alpha=0.3)

    # Plot 3: Anomaly Score vs Load Factor
    scatter = axes[1, 0].scatter(df['load_factor'], df['anomaly_score'],
                                 c=df['agents_detected'], cmap='Reds',
                                 alpha=0.6, s=30)
    axes[1, 0].set_title('Anomaly Score vs System Load')
    axes[1, 0].set_xlabel('Load Factor')
    axes[1, 0].set_ylabel('Anomaly Score')
    axes[1, 0].grid(True, alpha=0.3)
    plt.colorbar(scatter, ax=axes[1, 0], label='Agents Detected')

    # Plot 4: Agents Detected Over Time
    axes[1, 1].plot(df['timestamp'], df['agents_detected'].rolling(50).mean(), 
                    color='red', linewidth=2, label='50-point Moving Average')
    axes[1, 1].scatter(df['timestamp'], df['agents_detected'], color='darkred', alpha=0.3, s=10, label='Raw Data')
    axes[1, 1].set_title('Agent Detection Rate')
    axes[1, 1].set_xlabel('Timestamp')
    axes[1, 1].set_ylabel('Agents Detected')
    axes[1, 1].legend()
    axes[1, 1].grid(True, alpha=0.3)
    axes[1, 1].tick_params(axis='x', rotation=45)

    plt.tight_layout()
    plt.savefig(output_file, dpi=150, bbox_inches='tight')
    print(f"Analysis complete! Results saved to: {output_file}")
    print()


def show_package_comparison(dependencies):
    """
    Display comparison between pip and Poetry package management.

    Args:
        dependencies: Dictionary of dependency status
    """
    print("-------------------------------------------------")
    print("PACKAGE MANAGEMENT COMPARISON: pip vs Poetry")
    print("-------------------------------------------------")
    print()

    print("INSTALLED PACKAGES:")
    for pkg_name, (installed, version, _) in dependencies.items():
        if installed:
            print(f"  • {pkg_name}: {version}")
    print()

    print("KEY DIFFERENCES:")
    print()

    print("pip (requirements.txt):")
    print("  ✓ Simple and universal")
    print("  ✓ Works everywhere Python is installed")
    print("  ✓ Direct dependency specification")
    print("  ✗ No automatic dependency resolution")
    print("  ✗ No lock file by default")
    print("  ✗ Manual virtual environment management")
    print()

    print("Poetry (pyproject.toml):")
    print("  ✓ Automatic dependency resolution")
    print("  ✓ Lock file (poetry.lock) for reproducibility")
    print("  ✓ Built-in virtual environment management")
    print("  ✓ Separates dev and production dependencies")
    print("  ✓ Better project metadata handling")
    print("  ✗ Requires Poetry installation")
    print()

    print("RECOMMENDATION:")
    print("  • For simple scripts: Use pip + requirements.txt")
    print("  • For production projects: Use Poetry + pyproject.toml")
    print("  • For maximum compatibility: Provide both!")
    print()
    print("------------------------------------------------------")


if __name__ == "__main__":

    import pandas as pd

    all_ok, dependencies = check_dependencies()
    if not all_ok:
        installation_info()
        sys.exit(1)

    # Generate and analyze data
    df = generate_matrix_data()
    results = analyze_data(df)

    # Create visualization
    create_visualization(df)

    # Show package comparison
    show_package_comparison(dependencies)
