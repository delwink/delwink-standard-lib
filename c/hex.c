#include <string.h>
#include <ctype.h>

#include "hex.h"

int xtod(const char c)
{
    if (isdigit(c)) return c - '0';
    int extra = 0;

    switch (tolower(c)) {
        case 'a':
            extra = 1;
            break;
        case 'b':
            extra = 2;
            break;
        case 'c':
            extra = 3;
            break;
        case 'd':
            extra = 4;
            break;
        case 'e':
            extra = 5;
            break;
        case 'f':
            extra = 6;
            break;
    }

    return 9 + extra;
}

int htoi(const char *s)
{
    int i, n = 0;
    int prefix;

    if (strlen(s) > 3 && s[0] == '0' && tolower(s[1]) == 'x')
        prefix = 1;
    else
        prefix = 0;

    for (i = prefix ? 2 : 0; isxdigit(s[i]); ++i) {
        n = 0x10 * n + xtod(s[i]);
    }

    return n;
}
