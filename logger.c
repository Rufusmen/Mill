//
// Created by rufus on 28.01.18.
//

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>
#include "logger.h"

FILE *log;
bool initialized = false;
static char *log_level_strings[] = {
        "FATAL",
        "ERROR",
        "WARN ",
        "INFO ",
        "DEBUG"
};


int init_logger() {
    log = fopen("Mill.log", "a"); // open for appending
    if (log == NULL) {
        printf("Cannot open Mill.log for appending\n");
        return 1;
    }
    initialized = true;
    return 0;
}

void logger_log(enum LOGGER_LOG_LEVEL level, const char *fmt, ...) {
    if (level > LOGGER_MAX_LOG_LEVEL)
        return;

    if (!initialized)
        if (init_logger() != 0) // if cannot initialize logger, abort app
            abort();

    char prefix[32];
    char date[20];
    struct tm *sTm;
    time_t now = time(0);
    sTm = gmtime(&now);
    strftime(date, sizeof(date), "%Y-%m-%d %H:%M:%S", sTm);
    sprintf(prefix, "[%s] [%s]", date, log_level_strings[level]);

    va_list args;
    va_start(args, fmt);

    fprintf(log, "%s : ", prefix);
    vfprintf(log, fmt, args);
    fprintf(log, "\n");

    va_end(args);

    fflush(log);
}

int logger_close() {
    return fclose(log);
}