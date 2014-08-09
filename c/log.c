#include <string.h>
#include <time.h>
#include "log.h"
#include "datestamp.h"

const FILE *LOG_FILE;
const uint8_t LOGGING;

char *get_name();

void log_init(char *f)
{
    LOG_FILE = fopen(get_name(), "w");
    if (LOG_FILE == NULL) {
        LOGGING = 0;
    } else {
        LOGGING = 1;
    }
}

char *get_name()
{
    const char *ext = ".log";
    const int extlen = strlen(ext);
    int prelen = strlen(PROG);
    char *s = malloc(prelen+extlen+15);
    strcat(s, PROG);
    strcat(s, delwink_get_date_stamp());
    strcat(s, ext);
}
