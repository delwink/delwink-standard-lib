#include <string.h>
#include <time.h>
#include "log.h"
#include "datestamp.h"

const FILE *LOG_FILE;
const uint8_t LOGGING;

char *get_log_file_name(const char *);

char *log_init(const char *f)
{
    char *logfilename = get_log_file_name(f);
    LOG_FILE = fopen(logfilename, "w");
    if (LOG_FILE == NULL) {
        LOGGING = 0;
    } else {
        LOGGING = 1;
        return logfilename;
    }
    return NULL;
}

char *get_log_file_name(const char *loc)
{
    const char *ext = ".log";
    const int extlen = strlen(ext);
    int prelen = strlen(loc);
    char *s = malloc(prelen+extlen+15);
    strcat(s, loc);
    strcat(s, delwink_get_date_stamp());
    strcat(s, ext);

    return s;
}
