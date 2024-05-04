
# Finance Tracker Application

The Finance Tracker is a simple, menu-driven C application designed to help users manage their financial transactions. It allows users to add, display, and categorize transactions, view monthly summaries, and save/load transaction data for persistence.

## Features

- **Add Transactions:** Users can input transactions with a description, amount, and category.
- **Display Transactions by Category:** Allows users to view transactions filtered by specific categories.
- **Monthly Summary:** Provides a summary of total income, expenses, and net flow for the month.
- **Save/Load Transactions:** Users can save their transactions to a file and load them back, ensuring data persistence across sessions.
- **Edit/Delete Transactions:** Transactions can be modified or removed after they've been added. *(If implemented)*
- **Category Summaries:** View income and expenses summarized by categories. *(If implemented)*

## Installation

This application is written in C and requires a C compiler to build from source. Here's how you can compile and run the application on a Unix-like system:

1. **Clone the repository or download the source code:**

```bash
bfb41e06-6007-414f-aa0f-b04838803f25

git clone https://github.com/MohitGoyal09/Mini-project.git
cd finance-tracker

```

2. **Compile the application:**

```bash
gcc -o finance_tracker finance_tracker.c
```

3. **Run the application:**

```bash
./finance_tracker
```

## Usage

After launching the application, you will be presented with a menu of options:

1. **Add Transaction:** Follow the prompts to enter the transaction details.
2. **Display Transactions by Category:** Enter a category to view relevant transactions.
3. **Display Monthly Summary:** View a summary of the month's transactions.
4. **Save Transactions to File:** Enter a filename to save your transactions.
5. **Load Transactions from File:** Enter a filename to load transactions.
6. **Exit:** Exits the application.

Navigate through the application by entering the number corresponding to your choice at each menu.

## Contributing

Contributions to the Finance Tracker are welcome. Please follow the standard fork-clone-branch-pull request workflow.

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.

## Acknowledgments

- Thanks to all contributors who have helped to improve this application.

---

