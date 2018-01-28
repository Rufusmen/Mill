//
// Created by rufus on 28.01.18.
//

#ifndef MILL_LOGGER_H
#define MILL_LOGGER_H
#include <stdlib.h>
#include <stdbool.h>

#define LOGGER_MAX_LOG_LEVEL LOGGER_LOG_LEVEL_DEBUG

enum LOGGER_LOG_LEVEL{
    LOGGER_LOG_LEVEL_FATAL,
    LOGGER_LOG_LEVEL_ERROR,
    LOGGER_LOG_LEVEL_WARN,
    LOGGER_LOG_LEVEL_INFO,
    LOGGER_LOG_LEVEL_DEBUG
};

static int init_logger();

void logger_log(enum LOGGER_LOG_LEVEL level, const char *format, ...);

int logger_close();
#endif //MILL_LOGGER_H
