import sqlite3
import os

db_name = "hospital.db"

# 1. Reset Database
if os.path.exists(db_name):
    os.remove(db_name)
    print(f"Deleted old {db_name}")

conn = sqlite3.connect(db_name)
cursor = conn.cursor()

# 2. Define Structure
schema = """
    CREATE TABLE accounts (
        email TEXT PRIMARY KEY,
        password_hash INTEGER
    );

    CREATE TABLE patients (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        health_issue TEXT,
        blood_group TEXT,
        allergies TEXT,
        emergency_contact INTEGER,
        phone INTEGER
    );

    CREATE TABLE doctors (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT,
        specialization TEXT
    );

    CREATE TABLE reports (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        patient_name TEXT,
        email TEXT,
        health_issue TEXT
    );
"""

cursor.executescript(schema)
print("Database created successfully.")
conn.close()
