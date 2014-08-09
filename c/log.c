#include <time.h>
#include "log.h"

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
    
}
