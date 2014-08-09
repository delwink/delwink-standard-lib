#ifndef _DELWINK_LOG_H
#define _DELWINK_LOG_H

#include <stdio.h>
#include <stdint.h>

#define PROG "FIXME"

extern const FILE *LOG_FILE;
extern const uint8_t LOGGING;

/**
 * Initializes logging to `file`
 */
void log_init(char *file);

#define log_info(M, ...) {\
    fprintf(stdout, "[INFO] " M "\n", ##__VA_ARGS__);\
    if (LOGGING) fprintf(LOG_FILE, "[INFO] " M "\n", ##__VA_ARGS__);\
}

#define log_warn(M, ...) {\
    fprintf(stdout, "[WARNING] " M "\n", ##__VA_ARGS__);\
    if (LOGGING) fprintf(LOG_FILE, "[WARNING] " M "\n", ##__VA_ARGS__);\
}

#define log_err(M, ...) {\
    fprintf(stderr, "[FATAL] " M "\n", ##__VA_ARGS__);\
    if (LOGGING) fprintf(LOG_FILE, "[FATAL] " M "\n", ##__VA_ARGS__);\
}

#endif
