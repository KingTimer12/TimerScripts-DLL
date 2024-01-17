#include <stdio.h>
#include <stdlib.h>

#include "headers/api.h"
#include "headers/account.h"

int main(int argc, char *argv[]) {
    putenv(argv[1]); // Temporário
    struct API* TimerScriptsAPI = new_API();
    struct Account* Account = new_Account(TimerScriptsAPI);
    login(Account, "KingTimer12");

    return 0;
}
