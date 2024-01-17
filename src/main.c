#include <stdio.h>
#include "headers/api.h"

int main() {
    struct API* TimerScriptsAPI;
    TimerScriptsAPI = new_API();

    printf("%s", getUser(TimerScriptsAPI, "KingTimer12"));

    return 0;
}
