#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"

User* userTable[HASH_SIZE] = {NULL};

unsigned int hash(char* str)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = (hash << 5) + *str++;
    }
    return hash % HASH_SIZE;
}

User* findUser(char* username)
{
    int idx = hash(username);
    User* curr = userTable[idx];
    while(curr)
    {
        if(strcmp(curr->username, username) == 0)
            return curr;
        curr = curr->next;
    }
    return NULL;
}

void registration(char* username, char* password)
{
    if(findUser(username))
    {
        printf("User already exists \n");
        return;
    }
    int idx = hash(username);
    User* newUser = (User*)malloc(sizeof(User));
    strcpy(newUser->username, username);
    strcpy(newUser->password, password);
    newUser->jobs = NULL;
    newUser->next = userTable[idx];
    userTable[idx] = newUser;
    printf("User Registered\n");
}

void registerUser(char* username, char* password)
{
    registration(username, password);
}
