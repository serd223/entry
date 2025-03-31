#include <stdio.h>
#include <stdlib.h>

#define ENTRY_IMPLEMENTATION
#include "entry.h"

int main(void) {
    char* code =
        "ftext print" // Set current cell to user input and echo it
        "<add add add add add add add add add add print>" // Print newline
        "if rev dec nfi rev" // Decrement current cell until it is <= zero
        ">" // Switch to new 0 cell
        "add add add add add add add add add" // Set current cell to 9
        "ifrevdec> add add add add add add add add <nfirev" // Add 8 to the adjacent cell every iteration to set it to 8*9 = 72
        "> print" // Switch to the cell with the value of 72 and print it
        "<<<print" // Print newline
    ;
    switch (go(code)) {
    case WHEREISTHEHOLE:
        printf("[RUNTIME ERROR] WHEREISTHEHOLE\n");
        break;
    case TODO:
        printf("[RUNTIME ERROR] TODO\n");
        break;
    case WTF:
        printf("[RUNTIME ERROR] WTF\n");
        break;
    case HELLNAH:
        printf("[RUNTIME ERROR] HELLNAH\n");
        break;
    case YUMMY:
        break;
    default:
        abort();
    };
    return 0;
}
