#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "smart_ledger.h"
#include "finance_ops.h"
#include "ui.h"
#include "storage.h"

// Instantiate global variables
Transaction ledger[100];
int count = 0;

int main() {
    // 1. Load data on startup
    load_data("data.csv");

    int choice;

    // [Course Tech] Do-While Loop: Main menu loop
    do {
        system("cls"); // Clear screen
        show_welcome_message();

        // Display current financial status
        double balance = calculate_balance(ledger, count);
        printf("Current Balance: ");
        if (balance >= 0) set_color(10); // Green for positive
        else set_color(12); // Red for negative
        printf("$%.2f\n", balance);
        set_color(7);

        print_separator();
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View All Records\n");
        printf("4. Sort by Amount (High -> Low)\n");
        printf("0. Save & Exit\n");
        print_separator();
        printf("Please select an option: ");

        // Check if input is valid number
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear buffer
            choice = -1;
        }

        // [Course Tech] Switch Case
        switch (choice) {
        case 1: // Add Income
        case 2: // Add Expense
            if (count >= 100) {
                show_alert("Error", "Memory full! Cannot add more records.");
                break;
            }
            ledger[count].id = count + 1;
            ledger[count].type = (choice == 1) ? 1 : 0;

            printf("Enter Date (YYYY-MM-DD): ");
            scanf("%s", ledger[count].date);
            printf("Enter Amount: ");
            scanf("%lf", &ledger[count].amount);
            printf("Enter Note (No spaces): ");
            scanf("%s", ledger[count].note);

            count++;
            show_alert("Success", "Record added successfully!");
            break;

        case 3: // View Records
            printf("\nID\tDate\t\tType\tAmount\tNote\n");
            print_separator();
            for (int i = 0; i < count; i++) {
                if (ledger[i].type == 1) set_color(10); // Green for Income
                else set_color(12); // Red for Expense

                printf("%d\t%s\t%s\t%.0f\t%s\n",
                    ledger[i].id,
                    ledger[i].date,
                    (ledger[i].type == 1) ? "Income" : "Expense",
                    ledger[i].amount,
                    ledger[i].note);
            }
            set_color(7);
            printf("\n");
            system("pause");
            break;

        case 4: // Sorting
            sort_by_amount(ledger, count);
            show_alert("Completed", "Records sorted by amount (Descending).");
            break;

        case 0: // Exit
            save_data("data.csv");
            show_alert("Goodbye", "Data saved. System shutting down.");
            break;

        default:
            printf("Invalid option, please try again.\n");
            system("pause");
        }

    } while (choice != 0);

    return 0;
}