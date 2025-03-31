#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int32_t sandwich[256];
    size_t ps; // pizza slicer type shi
    bool direction;
    bool skip;
} Entry;

typedef enum {
    WHEREISTHEHOLE, // File not found
    TODO, // Illegal instruction
    WTF, // Print error
    HELLNAH, // Segmentation fault
    YUMMY // OK
} HEADACHE;

HEADACHE go(char* fs);

#ifdef ENTRY_IMPLEMENTATION

#define __SKIP \
if (entry.skip) {\
    entry.skip = false;\
} else\

// code is assumed to be null-terminated
HEADACHE go(char* code) {
    Entry entry = {0};
    while (code && *code) {
        char buffer[6] = {0};
        for (int i = 0; i < 5; ++i) {
            char c = *(code + i);
            if (c) {
                buffer[i] = c;
            } else {
                break;
            }
            if (i == 0) {
                // > and <
                if (buffer[0] == '>') {
                    __SKIP {
                        if (!entry.direction) {
                            entry.ps++;
                            if (entry.ps >= 256) entry.ps = 0;
                        } else {
                            if (entry.ps == 0) entry.ps = 256;
                            entry.ps--;
                        }
                    }
                    break;
                } else if (buffer[0] == '<') {
                    __SKIP {
                        if (entry.direction) {
                            entry.ps++;
                            if (entry.ps >= 256) entry.ps = 0;
                        } else {
                            if (entry.ps == 0) entry.ps = 256;
                            entry.ps--;
                        }
                    }
                    break;
                }
            } else if (i == 1) {
                // if
                if (!strcmp(buffer, "if")) {
                    __SKIP {
                        entry.skip = (entry.sandwich[entry.ps] > 0);
                    }
                    break;
                }
            } else if (i == 2) {
                // add, dec and rev
                if (!strcmp(buffer, "add")) {
                    __SKIP {
                        entry.sandwich[entry.ps]++;
                    }
                    break;
                    
                } else if (!strcmp(buffer, "dec")) {
                    __SKIP {
                        entry.sandwich[entry.ps]--;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "rev")) {
                    __SKIP {
                        entry.direction = !entry.direction;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "nfi")) {
                    __SKIP {
                        entry.skip = (entry.sandwich[entry.ps] <= 0);
                    }
                    break;
                }
            } else if (i == 4) {
                // print and ftext
                if (!strcmp(buffer, "print")) {
                    __SKIP {
                        int32_t i = entry.sandwich[entry.ps];
                        if (i >= 256) {
                            return WTF;
                        }
                        printf("%c", (char)i);
                    }
                    break;
                    
                } else if (!strcmp(buffer, "ftext")) {
                    __SKIP {
                        entry.sandwich[entry.ps] = fgetc(stdin);
                    }
                    break;
                }
            }
        }
        if (entry.direction) {
            --code;
        } else {
            ++code;
        }
    }

    return YUMMY;    
}
#endif // ENTRY_IMPLEMENTATION

#endif // __ENTRY_H__
