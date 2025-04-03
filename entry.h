#ifndef __ENTRY_H__
#define __ENTRY_H__

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int32_t stack[256];
    size_t sptr;
    bool direction;
    bool skip;
} Entry;

typedef enum {
    PRINT_ERROR, // Current cell is above 255
    OK // OK
} EntryError;

EntryError go(char* code);

#ifdef ENTRY_IMPLEMENTATION

#define ___SKIP        \
if (entry.skip) {      \
    entry.skip = false;\
} else                 \

// code is assumed to be null-terminated
EntryError go(char* code) {
    Entry entry = {0};
    char* begin = code;
    while (code && code >= begin && *code) {
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
                    ___SKIP {
                        if (!entry.direction) {
                            entry.sptr++;
                            if (entry.sptr >= 256) entry.sptr = 0;
                        } else {
                            if (entry.sptr == 0) entry.sptr = 256;
                            entry.sptr--;
                        }
                    }
                    break;
                } else if (buffer[0] == '<') {
                    ___SKIP {
                        if (entry.direction) {
                            entry.sptr++;
                            if (entry.sptr >= 256) entry.sptr = 0;
                        } else {
                            if (entry.sptr == 0) entry.sptr = 256;
                            entry.sptr--;
                        }
                    }
                    break;
                }
            } else if (i == 1) {
                // if
                if (!strcmp(buffer, "if")) {
                    ___SKIP {
                        entry.skip = (entry.stack[entry.sptr] > 0);
                    }
                    break;
                }
            } else if (i == 2) {
                // add, dec, rev and nfi
                if (!strcmp(buffer, "add")) {
                    ___SKIP {
                        entry.stack[entry.sptr]++;
                    }
                    break;
                    
                } else if (!strcmp(buffer, "dec")) {
                    ___SKIP {
                        entry.stack[entry.sptr]--;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "rev")) {
                    ___SKIP {
                        entry.direction = !entry.direction;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "nfi")) {
                    ___SKIP {
                        entry.skip = (entry.stack[entry.sptr] <= 0);
                    }
                    break;
                }
            } else if (i == 4) {
                // print and input
                if (!strcmp(buffer, "print")) {
                    ___SKIP {
                        int32_t i = entry.stack[entry.sptr];
                        if (i >= 256) {
                            return PRINT_ERROR;
                        }
                        printf("%c", (char)i);
                    }
                    break;
                    
                } else if (!strcmp(buffer, "input")) {
                    ___SKIP {
                        entry.stack[entry.sptr] = fgetc(stdin);
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

    return OK;    
}
#endif // ENTRY_IMPLEMENTATION

#endif // __ENTRY_H__
