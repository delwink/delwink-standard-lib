#ifndef _DELWINK_LOG_H
#define _DELWINK_LOG_H

#include <stdio.h>
#include <stdint.h>

const FILE *LOG_FILE;
extern const uint8_t LOGGING;

/**
 * Initializes logging to a file in `path`
 * Returns full path to log file
 */
char *log_init(char *path);

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
