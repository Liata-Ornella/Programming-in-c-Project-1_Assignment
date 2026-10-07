#include <stdio.h>

int main()
{
    double balance = 0.0;
    double amount;

    int choice;
    int successfulDeposits = 0;
    int successfulWithdrawals = 0;

    while (1)
    {
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter deposit amount: ");
                scanf("%lf", &amount);

                if (amount <= 0)
                {
                    printf("Transaction rejected: Amount must be positive.\n");
                    continue;
                }

                balance += amount;
                successfulDeposits++;

                printf("Deposit successful.\n");
                printf("Current balance: %.2f RWF\n", balance);
                break;

            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%lf", &amount);

                if (amount <= 0)
                {
                    printf("Transaction rejected: Amount must be positive.\n");
                    continue;
                }

                if (amount > balance)
                {
                    printf("Transaction rejected: Insufficient balance.\n");
                    continue;
                }

                balance -= amount;
                successfulWithdrawals++;

                printf("Withdrawal successful.\n");
                printf("Current balance: %.2f RWF\n", balance);
                break;

            case 3:
                printf("Current balance: %.2f RWF\n", balance);
                break;

            case 4:
                printf("\n===== TRANSACTION SUMMARY =====\n");
                printf("Successful deposits: %d\n", successfulDeposits);
                printf("Successful withdrawals: %d\n", successfulWithdrawals);
                printf("Current balance: %.2f RWF\n", balance);
                break;

            case 5:
                printf("System terminated.\n");
                break;

            default:
                printf("Invalid choice. Please select a number from 1 to 5.\n");
                continue;
        }

        if (choice == 5)
        {
            break;
        }
    }

    return 0;
}