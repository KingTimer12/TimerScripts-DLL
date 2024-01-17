#ifndef API_H
#define API_H

struct API;
struct API* new_API(void);

char* getUser(struct API*, char* username);

#endif