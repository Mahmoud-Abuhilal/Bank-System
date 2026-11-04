# Object-Oriented Banking Management System (C++)

A robust, console-based banking management and currency exchange platform built in modern C++. This application demonstrates advanced Object-Oriented Programming (OOP) principles, clean dynamic memory handling, screen-based UI abstraction, and file-based data persistence.

## Key Features

- **Client Management:** Complete CRUD operations (Create, Read, Update, Delete) for client accounts, including balance tracking and account search.
- **Transaction Engine:** Deposit and withdrawal workflows, account transfers, real-time balance calculations, and automated transfer logging.
- **User & Permission System:** Multi-user authentication with fine-grained action permissions, login registration logging, and user management.
- **Currency Exchange:** Live rate management, currency conversion calculator, and multi-currency lookup screens.
- **Input Validation:** Centralized, robust input validation library (`clsInputValidate`) for string handling, date manipulation (`clsDate`), and numerical boundary checks.

## Architecture & OOP Design

The system relies on strong separation of concerns:
- **Core Entities:** Domain model classes like `clsBankClient`, `clsUser`, `clsCurrency`, and `clsPerson`.
- **UI / Presentation Layer:** Independent screen objects inheriting from `clsScreen` (e.g., `clsMainScreen`, `clsTransactionsScreen`, `clsLoginScreen`).
- **Data Persistence:** File I/O structure maintaining decoupled text-database operations (`Clients.txt`, `Users.txt`, `TransferLog.txt`).

## Tech Stack & Environment

- **Language:** C++ (C++17 standard)
- **Compiler:** GCC / Clang / MSVC
- **IDE / Tools:** Visual Studio 2022, Vim, Linux / Windows

## How to Build and Run

### Visual Studio (Windows)
1. Clone the repository:
   ```bash
   git clone https://github.com/Mahmoud-Abuhilal/Bank-System.git
   ```
2. Open `Bank System.sln` in Visual Studio 2022.
3. Build and run the solution (`Ctrl + F5`).

### GCC / Clang (Linux / Bash)
1. Compile using GCC:
   ```bash
   g++ -std=c++17 "Bank System/Bank System.cpp" -o BankSystem
   ```
2. Execute the application:
   ```bash
   ./BankSystem
   ```

## License
This project is open-source and available under the MIT License.