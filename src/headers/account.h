#include "api.h"

#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account;
struct Account* new_Account(struct API*);

int login(struct Account*, char* username);

#endif