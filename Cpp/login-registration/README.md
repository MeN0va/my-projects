# 🔐 Login & Registration System (C++)

A simple console-based login and registration system written in C++.
This project was created as a **learning exercise**, not as a secure or production-ready authentication system.

## ✨ Features

- User registration
- User authentication
- Password hashing
- File-based storage (`users.txt`)
- Simple class-based design

## 🧰 How It Works

1. During **registration**:
   - The user enters a username and password
   - The password is hashed
   - The username and hashed password are saved to a file

2. During **login**:
   - The user enters a username and password
   - The password is hashed again
   - The program checks for a matching username + hash pair

## 📁 File Storage

User data is stored in a plain text file "users.txt"
Each line contains: <username> <hashed_password>
This file is created automatically if it does not exist.

## ⚠️  Known Limitations

This project is intentionally simple and has several limitations:

- Uses `std::hash`, which is **not cryptographically secure**
- No password salting
- Data stored in plain text
- File-based storage does not scale
- No database integration
- No input validation beyond basic constraints

## 🧪 Why This Project Exists

This project was built to practice and understand:
- C++ file I/O
- class design
- authentication flow
- hashing concepts
- basic program structure

## 🛠️  How to Run

```bash
g++ user_auth.cpp -o program
./program
```
## 🧠 Future Improvements

Possible areas for improvement:

* proper cryptographic hashing (e.g. bcrypt, Argon2)
* password salting
* database storage (e.g. MySQL)
