\# Hospital Management System



This is a C++ command-line application designed to handle patient and staff records using a local SQLite database.



\## Functionality

\- Authenticates staff and medical users.

\- Stores patient demographics, health issues, and emergency contacts.

\- Matches patients with available doctors based on specialization.

\- Persists all data in a local hospital.db file.



\## Requirements

\- C++17 or higher

\- CMake 3.15+

\- SQLite3 (included in source)

\- Python (for initial database setup)



\## Setup

1\. Run setup.py to initialize the database tables.

2\. Build the project using the provided CMakeLists.txt.

3\. Ensure hospital.db is in the same directory as the compiled executable.



\## Development Note

The project uses a hybrid approach: Python for rapid database schema deployment ,SQLite for data debugging and C++ for the core application logic and data processing.

