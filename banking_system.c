#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    long int accNo;
    char name[50];
    float balance;
};

void createAccount();
void deposit();
void withdrawAmount();
void checkBalance();
void displayAll();

int main() {
    int choice;

    while (1) {
        printf("\n====== BANKING SYSTEM ======\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            exit(0);
        }

        switch (choice) {
        case 1: createAccount(); break;
        case 2: deposit(); break;
        case 3: withdrawAmount(); break;
        case 4: checkBalance(); break;
        case 5: displayAll(); break;
        case 6:
            printf("Thank you for using the banking system!\n");
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }
}

void createAccount() {
    struct Account acc, temp;
    FILE *fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
        fp = fopen("accounts.dat", "wb+");

    if (fp == NULL) {
        printf("File error!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%ld", &acc.accNo);

    while (fread(&temp, sizeof(struct Account), 1, fp)) {
        if (temp.accNo == acc.accNo) {
            printf("Account already exists!\n");
            fclose(fp);
            return;
        }
    }

    getchar(); 
    printf("Enter Name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    acc.name[strcspn(acc.name, "\n")] = '\0';

    printf("Enter Initial Deposit: ");
    scanf("%f", &acc.balance);

    if (acc.balance < 0) {
        printf("Invalid amount!\n");
        fclose(fp);
        return;
    }

    fwrite(&acc, sizeof(struct Account), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}

void deposit() {
    struct Account acc;
    long int accNo;
    float amount;
    int found = 0;

    FILE *fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%ld", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Account Holder: %s\n", acc.name);
            printf("Current Balance: %.2f\n", acc.balance);

            printf("Enter amount to deposit: ");
            scanf("%f", &amount);

            if (amount <= 0) {
                printf("Invalid amount!\n");
                fclose(fp);
                return;
            }

            acc.balance += amount;
            fseek(fp, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, fp);

            printf("Deposit successful!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void withdrawAmount() {
    struct Account acc;
    long int accNo;
    float amount;
    int found = 0;

    FILE *fp = fopen("accounts.dat", "rb+");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%ld", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("Account Holder: %s\n", acc.name);
            printf("Current Balance: %.2f\n", acc.balance);

            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);

            if (amount <= 0 || amount > acc.balance) {
                printf("Invalid or insufficient balance!\n");
                fclose(fp);
                return;
            }

            acc.balance -= amount;
            fseek(fp, -sizeof(struct Account), SEEK_CUR);
            fwrite(&acc, sizeof(struct Account), 1, fp);

            printf("Withdrawal successful!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void checkBalance() {
    struct Account acc;
    long int accNo;
    int found = 0;

    FILE *fp = fopen("accounts.dat", "rb");
    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\nEnter Account Number: ");
    scanf("%ld", &accNo);

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        if (acc.accNo == accNo) {
            printf("\nName: %s", acc.name);
            printf("\nBalance: %.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void displayAll() {
    struct Account acc;
    FILE *fp = fopen("accounts.dat", "rb");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n===== ALL ACCOUNTS =====\n");

    while (fread(&acc, sizeof(struct Account), 1, fp)) {
        printf("Acc No: %ld | Name: %s | Balance: %.2f\n",
               acc.accNo, acc.name, acc.balance);
    }

    fclose(fp);
}