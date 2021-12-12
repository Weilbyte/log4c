#include <stdio.h>
#include <log4c.h>

int main() {
    log4c("Starting example");
    
    #ifdef _WIN32
        log4c("Running on Windows!");
        log4c("${whoami && calc.exe}");
    #else
        log4c("Running on Unix (or something else)!");
        log4c("${whoami}");
    #endif
}