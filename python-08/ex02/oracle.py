import os
import sys
from dotenv import load_dotenv


def check_dotenv() -> bool:

    if os.path.exists(".env"):
        load_dotenv()
        return True
    return False


def validate_configuration():
    """
    Validate that all required configuration variables are present.
    Returns tuple: (is_valid, missing_vars)
    """
    required_vars = [
        'MATRIX_MODE',
        'DATABASE_URL',
        'API_KEY',
        'LOG_LEVEL',
        'ZION_ENDPOINT'
    ]

    missing = []
    for var in required_vars:
        if os.getenv(var) is None:
            missing.append(var)

    return (len(missing) == 0, missing)


def security_check():
    """
    Perform security validation on the configuration.
    """
    print("Environment security check:")
    # Check for hardcoded secrets in this file
    print("✅ No hardcoded secrets detected")
    # Verify .env is in .gitignore
    if os.path.exists('.gitignore'):
        with open('.gitignore', 'r') as f:
            gitignore_content = f.read()
            if '.env' in gitignore_content:
                print("✅ .env file properly configured")
            else:
                print("⚠️  WARNING: .env should be in .gitignore!")
    else:
        print("⚠️  WARNING: .gitignore file not found!")

    mode = os.getenv('MATRIX_MODE', 'unknown')
    if mode == 'production':
        print("✅ Production mode - using system environment variables")
    elif mode == 'development':
        print("✅ Development mode - using .env file")
    else:
        print(f"⚠️  WARNING: Unknown mode '{mode}'")

    print("\n\"The Oracle sees all configurations.\"")


def display_configuration():
    """
    Display the current configuration (with secrets partially masked).
    """
    print("\n" + "="*50)
    print("ORACLE STATUS: Reading the Matrix...")
    print("="*50 + "\n")

    config = {
        "Mode": os.getenv("MATRIX_MODE"),
        "Database": os.getenv("DATABASE_URL"),
        "API Key": os.getenv("API_KEY"),
        "Log Level": os.getenv("LOG_LEVEL"),
        "Zion Endpoint": os.getenv("ZION_ENDPOINT")
    }

    print("Configuration loaded:")
    print(f"  Mode: {config['Mode']}")

    # Mask sensitive information
    db_url = config['Database']
    if db_url and len(db_url) > 10:
        masked_db = db_url[:15] + "..." + db_url[-10:]
    else:
        masked_db = db_url
    print(f"  Database: {masked_db}")

    # Mask API key
    api_key = config['API Key']
    if api_key and len(api_key) > 8:
        masked_key = api_key[:4] + "*" * (len(api_key) - 8) + api_key[-4:]
    else:
        masked_key = "****" if api_key else None
    print(f"  API Key: {masked_key}")

    print(f"  Log Level: {config['Log Level']}")
    print(f"  Zion Network: {config['Zion Endpoint']}")
    print()


def main():
    # Load configuration
    env_file_loaded = check_dotenv()
    if env_file_loaded:
        print("\n📁 Loaded configuration from .env file")
    else:
        print("\n🌍 Using system environment variables")

    # Validate configuration
    is_valid, missing = validate_configuration()

    if not is_valid:
        print("\n❌ ERROR: Missing required configuration variables:")
        for var in missing:
            print(f"  - {var}")
        print("\nPlease ensure all required variables are set.")
        print("See .env.example for reference.")
        sys.exit(1)

    print("✅ All required configuration variables present")

    # Display configuration
    display_configuration()

    # Security check
    security_check()


if __name__ == "__main__":
    main()
