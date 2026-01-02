#define _CRT_SECURE_NO_WARNINGS
#include "storage.h"

// [Course Tech] File I/O: Read from file
void load_data(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        return; // File doesn't exist, assume new user
    }

    count = 0;
    // Format: ID, Date, Type, Amount, Note
    while (fscanf(fp, "%d,%[^,],%d,%lf,%s\n",
        &ledger[count].id,
        ledger[count].date,
        &ledger[count].type,
        &ledger[count].amount,
        ledger[count].note) != EOF) {
        count++;
    }
    fclose(fp);
}

// [Course Tech] File I/O: Write to file
void save_data(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Cannot save file!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%d,%s,%d,%.2f,%s\n",
            ledger[i].id,
            ledger[i].date,
            ledger[i].type,
            ledger[i].amount,
            ledger[i].note);
    }
    fclose(fp);
    printf("System auto-save completed.\n");
}