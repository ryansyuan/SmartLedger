#ifndef SMART_LEDGER_H
#define SMART_LEDGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [Course Tech] Struct: Define transaction structure
typedef struct {
    int id;             // ID
    char date[12];      // Date string (YYYY-MM-DD)
    int type;           // 0: Expense, 1: Income
    double amount;      // Monetary amount
    char note[100];     // Description/Note
} Transaction;

// [Course Tech] Array: Global variable declaration, max 100 records
extern Transaction ledger[100];
extern int count;

#endif
