#define _CRT_SECURE_NO_WARNINGS
#include "finance_ops.h"

// [Course Tech] Pointer & Loop: Calculate total expense
double calculate_total_expense(Transaction* data, int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].type == 0) { // 0 represents Expense
            total += data[i].amount;
        }
    }
    return total;
}

// [Course Tech] Pointer & Loop: Calculate total income
double calculate_total_income(Transaction* data, int n) {
    double total = 0;
    for (int i = 0; i < n; i++) {
        if (data[i].type == 1) { // 1 represents Income
            total += data[i].amount;
        }
    }
    return total;
}

// Calculate current balance
double calculate_balance(Transaction* data, int n) {
    return calculate_total_income(data, n) - calculate_total_expense(data, n);
}

// [Course Tech] Algorithm: Bubble Sort (Sort by amount descending)
void sort_by_amount(Transaction* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].amount < data[j + 1].amount) { // Swap if current is smaller than next
                Transaction temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}