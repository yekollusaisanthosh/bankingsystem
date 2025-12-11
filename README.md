Banking System in C
This project is a simple file-based Banking Management System written in C.
It allows users to create accounts, deposit and withdraw money, check balances, and view all registered accounts.
Data is stored permanently using a binary file (accounts.dat).

📌 Features Implemented
✔ Create New Account
User enters an account number, name, and initial deposit.
Program checks if an account number already exists before adding.
✔ Deposit Money
Adds money to an existing account.
Ensures deposit amount is positive.
✔ Withdraw Money
Allows money withdrawal with balance validation.
Prevents overdraft (cannot withdraw more than the balance).
✔ Check Balance
Displays the account holder’s name and current balance.
✔ Display All Accounts
Shows account number, name, and balance for all stored accounts.
✔ Persistent Storage
All data stored in accounts.dat using binary file handling.
File is created automatically if it doesn't exist.
📂 Files Included
File	Purpose
banking_system.c	Main source code containing the entire banking system program
accounts.dat	Binary file created at runtime to store account records
README.md	Documentation for understanding and using the project
Makefile (optional)	Automates compilation if included
▶ How to Compile & Run
Using GCC
gcc banking_system.c -o banking
./banking

make
./banking

🧪 Sample Output

Program Start
====== BANKING SYSTEM ======
1. Create Account
2. Deposit Amount
3. Withdraw Amount
4. Check Balance
5. Display All Accounts
6. Exit
Enter your choice:

Creating an Account
Enter Account Number: 101
Enter Name: Rahul
Enter Initial Deposit: 5000
Account created successfully!

Depositing Money
Enter Account Number: 101
Account Holder: Rahul
Current Balance: 5000
Enter amount to deposit: 1500
Deposit successful!

Withdrawing Money
Enter Account Number: 101
Account Holder: Rahul
Current Balance: 6500
Enter amount to withdraw: 2000
Withdrawal successful!

Checking Balance
Enter Account Number: 101
Name: Rahul
Balance: 4500

Displaying All Accounts
===== ALL ACCOUNTS =====
Acc No: 101 | Name: Rahul | Balance: 4500.00

📝 Notes & Assumptions

Account numbers must be unique integers.

Names are stored as strings (max 50 characters).

The binary file accounts.dat is created automatically.

Invalid inputs (strings instead of numbers) will terminate the program due to scanf failure.

Negative deposits or withdrawals are not allowed.

Withdrawal cannot exceed the available balance.

The program uses:

fread(), fwrite() for reading/writing account records

fseek() to update records in place

File mode rb+ / wb+ for persistent storage
