#include "headers/api.h"

#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t WriteCallback(void *contents, size_t size, size_t nmemb, char **output)
{
    size_t total_size = size * nmemb;
    *output = (char *)realloc(*output, total_size + 1);
    if (*output == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória.\n");
        return 0;
    }
    memcpy(*output, contents, total_size);
    (*output)[total_size] = '\0';
    return total_size;
}

struct API
{
    char *URL;
};

struct API *new_API(void)
{
    struct API *newApi;
    newApi = malloc(sizeof(struct API));
    newApi->URL = getenv("LINK");
    return newApi;
}

char *getUser(struct API *newApi, char *username)
{
    CURL *curl;
    CURLcode res;
    char *response = NULL;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl)
    {
        size_t sizeURL = strlen(newApi->URL);
        size_t sizeUsername = strlen(username);
        size_t sizeNewURL = sizeURL + 1 + sizeUsername + 1;
        char *newURL = (char *)malloc(sizeNewURL);

        strcpy(newURL, newApi->URL);
        strcat(newURL, "/");
        strcat(newURL, username);

        curl_easy_setopt(curl, CURLOPT_URL, newURL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            free(newURL);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return curl_easy_strerror(res);
        }

        free(newURL);
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return response;
}