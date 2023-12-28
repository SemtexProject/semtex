import subprocess

# Check if alembic is installed
try:
    import alembic
except ImportError:
    print("Alembic is not installed. Please install it with 'pip install alembic'")
    exit(1)
finally:
    del alembic
    subprocess.run(["alembic", "revision", "--autogenerate", "-m", "[Auto-generated migration <entry.py>]"])
    subprocess.run(["alembic", "upgrade", "head"])


from main import app