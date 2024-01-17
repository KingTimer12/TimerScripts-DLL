#include <stdio.h>
#include <stdlib.h>
#include "headers/api.h"

int main(int argc, char *argv[]) {
    struct API* TimerScriptsAPI;

    putenv(argv[1]); // Temporário

    TimerScriptsAPI = new_API();
    printf("%s", getUser(TimerScriptsAPI, "KingTimer12"));

    return 0;
}
