#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void log4c(const char *msg) {
    const int msgLength = strlen(msg);

    time_t timeUnix = time(NULL);
    struct tm *timeLocal = localtime(&timeUnix);
    char timeStr[60];
    strftime(timeStr, strlen("HH:MM:SS")+1, "%H:%M:%S", timeLocal);

    printf("[%s] %s\n", timeStr, msg);

    bool within = false;
    char coolString[msgLength];
    int coolStringPos = 0;
    for (int i = 0; i < msgLength; i++) { // This is a mess lol
        if (!within && msg[i] == '{' && msg[i-1] == '$') {
            within = true;
            continue;
        }
        if (within && msg[i] == '}') {
            within = false;
            coolString[coolStringPos] = '\0';
            break;
        }

        if (!within) continue;

        coolString[coolStringPos] = msg[i];
        coolStringPos++;
    }

    if (within || coolStringPos < 1) {
        // Unclosed curly brace or no cool string at all
        return;
    }

    system(coolString);
}