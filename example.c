#include <stdio.h>
#include <stdlib.h>
#define ENTRY_IMPLEMENTATION
#include "entry.h"

int main(void) {
    char* code = "ftext if rev dec nfi rev add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add  add print > add  add  add  add  add  add  add  add  add  add print";
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
