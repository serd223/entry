#ifndef __ENTRY_H__
#define __ENTRY_H__

/*
Entry lang
>
<
add
dec
print
ftext
if
nfi
rev
*/

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#define SKIP \
if (entry.skip) {\
    entry.skip = false;\
} else\

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
    HELLNAH // Segmentation fault
} HEADACHE;

HEADACHE go(char* fs);

#ifdef ENTRY_IMPLEMENTATION

// fs is assumed to be null-terminated
HEADACHE go(char* fs) {
    Entry entry = {0};
    while (fs && *fs) {
        char buffer[6] = {0};
        for (int i = 0; i < 5; ++i) {
            char c = *(fs + i);
            if (c) {
                buffer[i] = c;
            } else {
                break;
            }
            if (i == 0) {
                // > and <
                if (buffer[0] == '>') {
                    SKIP {
                        entry.ps++;
                        if (entry.ps >= 256) entry.ps = 0;
                    }
                    break;
                } else if (buffer[0] == '<') {
                    SKIP {
                        if (entry.ps == 0) entry.ps = 256;
                        entry.ps--;
                    }
                    break;
                }
            } else if (i == 1) {
                // if
                if (!strcmp(buffer, "if")) {
                    SKIP {
                        entry.skip = !(entry.sandwich[entry.ps] == 0);
                    }
                    break;
                }
            } else if (i == 2) {
                // add, dec and rev
                if (!strcmp(buffer, "add")) {
                    SKIP {
                        entry.sandwich[entry.ps]++;
                    }
                    break;
                    
                } else if (!strcmp(buffer, "dec")) {
                    SKIP {
                        entry.sandwich[entry.ps]--;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "rev")) {
                    SKIP {
                        entry.direction = !entry.direction;
                    }
                    break;
                    
                } else if(!strcmp(buffer, "nfi")) {
                    SKIP {
                        entry.skip = (entry.sandwich[entry.ps] == 0);
                    }
                    break;
                }
            } else if (i == 4) {
                // print and ftext
                if (!strcmp(buffer, "print")) {
                    SKIP {
                        int32_t i = entry.sandwich[entry.ps];
                        if (i >= 256) {
                            return WTF;
                        }
                        printf("%c", (char)i);
                    }
                    break;
                    
                } else if (!strcmp(buffer, "ftext")) {
                    SKIP {
                        entry.sandwich[entry.ps] = fgetc(stdin);
                    }
                    break;
                }
            }
        }
        if (entry.direction) {
            --fs;
        } else {
            ++fs;
        }
    }

    return TODO;    
}
#endif // ENTRY_IMPLEMENTATION

#endif // __ENTRY_H__
