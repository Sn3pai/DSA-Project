#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "job.h"
#define MAX_USER 50
#define HASH_SIZE 100

typedef struct User
{
    char username[MAX_USER];
    char password[MAX_USER];
    Job* jobs;
    struct User* next;
} User;

extern User* userTable[HASH_SIZE];

User* findUser(char* username);
void registration(char* username, char* password);
void registerUser(char* username, char* password);
unsigned int hash(char* str);

#endif
