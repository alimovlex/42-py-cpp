import sys
import os


def is_in_venv():
    return sys.prefix != sys.base_prefix


if __name__ == "__main__":

    if not is_in_venv():
        print("MATRIX STATUS: You're still plugged in\n")
        print(f"Current Python: {sys.executable}")
        print("Virtual Environment: None detected")
        print()
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install")
        print()
        print("To enter the construct, run:")
        print("python -m venv matrix_env\n"
              "source matrix_env/bin/activate # On Unix\n"
              "matrix_env\n"
              "Scripts\n"
              "activate # On Windows")

    if is_in_venv():
        print("MATRIX STATUS: Welcome to the construct\n")
        print(f"Current Python: {sys.executable}")
        venv_path = os.environ.get("VIRTUAL_ENV")
        venv_name = os.path.basename(venv_path)
        print(f"Virtual Environment: {venv_name}")
        print(f"Environment Path: {venv_path}")
        print()
        print("SUCCESS: You're in an isolated environment!\n"
              "Safe to install packages without affecting\n"
              "the global system.")
        print()
        for path in sys.path:
            if "site-packages" in path:
                print(f"Package installation path: {path}")
