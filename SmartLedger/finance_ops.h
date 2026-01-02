#ifndef FINANCE_OPS_H
#define FINANCE_OPS_H

#include "smart_ledger.h"

// [Custom Library] Function declarations for financial calculations
double calculate_total_expense(Transaction* data, int n);
double calculate_total_income(Transaction* data, int n);
double calculate_balance(Transaction* data, int n);
void sort_by_amount(Transaction* data, int n); // Bonus: Sorting algorithm

#endif
