
#include <stdio.h>
#include "ansi_escapes.hpp"

void setupConsole(void) {}

void restoreConsole(void) {
    // Reset colors
    printf("\x1b[0m");
}
