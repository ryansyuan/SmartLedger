#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // [External Library] Windows API
#include "ui.h"

// [External Tech] Change text color in console
// 7: White, 10: Green, 12: Red, 14: Yellow
void set_color(int color_code) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color_code);
}

// [External Tech] Windows MessageBox API for pop-up alerts
void show_alert(char* title, char* message) {
    MessageBoxA(NULL, message, title, MB_OK | MB_ICONINFORMATION);
}

void print_separator() {
    set_color(7); // Reset to white
    printf("--------------------------------------------------\n");
}

void show_welcome_message() {
    set_color(14); // Yellow
    printf("\n");
    printf("      $$$ SMART LEDGER SYSTEM $$$      \n");
    printf("           Version 1.0 Beta            \n");
    printf("\n");
    set_color(7); // Reset to white
}