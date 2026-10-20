# CodeAlpha_LoginAndRegistrationSystem

A C++ Login and Registration System with file-based persistence, password hashing, and input validation.

## 🚀 Features

- **User Registration:** Validates username formats (minimum 4 characters, alphanumeric and underscore only) and enforces strong passwords (minimum 6 characters).
- **Duplicate Prevention:** Checks existing records to ensure unique usernames during registration.
- **Password Hashing:** Uses `std::hash` to store hashed passwords instead of plain text in the database file (`users.txt`).
- **Secure Authentication:** Validates login credentials against hashed values in real-time.
- **Robust Error Handling:** Protects against invalid inputs and handles file opening errors.

---

## 🛠️ Tech Stack & Concepts Used

- **Language:** C++
- **Concepts:**
  - File Handling (`std::ifstream`, `std::ofstream`)
  - Password Hashing (`std::hash`)
  - Object-Oriented Programming (Classes & Encapsulation)
  - String Operations & Input Validation (`isalnum`)

---

## 💻 How to Run

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/roysuljstu/CodeAlpha_LoginAndRegistrationSystem.git](https://github.com/roysuljstu/CodeAlpha_LoginAndRegistrationSystem.git)
