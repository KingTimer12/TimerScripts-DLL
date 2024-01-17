#include <jansson.h>
#include "headers/account.h"
#include "headers/api.h"

struct Account
{
    struct API *timerApi;
};

struct Account *new_Account(struct API *timerApi)
{
    struct Account *newAccount = malloc(sizeof(struct Account));
    newAccount->timerApi = timerApi;
    return newAccount;
}

int login(struct Account *account, char* username) {
    const char* user = getUser(account->timerApi, username);

    json_error_t error;
    json_t *root = json_loads(user, 0, &error);
    if (root) {
        const char* passwordRemote = json_string_value(json_object_get(root, "password"));

        json_t *effects_json = json_object_get(root, "effects");
        if (json_is_array(effects_json)) {
            size_t array_size = json_array_size(effects_json);
            printf("Username: %s\n", username);
            printf("Password: %s\n", passwordRemote);
            printf("Effects: ");
            for (size_t i = 0; i < array_size; ++i) {
                const char *effect = json_string_value(json_array_get(effects_json, i));
                printf("%s%s", effect, (i < array_size - 1) ? ", " : "");
            }
            printf("\n");
        }
    }
}