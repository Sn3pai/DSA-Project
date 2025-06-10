#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "job.h"
#include "fileio.h"

void saveJobstoFile(Job* root, FILE* file)
{
    if(!root)
        return;
    saveJobstoFile(root->left, file);
    fprintf(file, "%s,%d\n",root->title,root->status);
    saveJobstoFile(root->right, file);
}

void saveUserstoFile(const char* filename)
{
    FILE* file = fopen(filename, "w");
    for(int i = 0; i < HASH_SIZE; i++)
    {
        User* user = userTable[i];
        while(user)
        {
            fprintf(file, "User,%s,%s\n", user->username, user->password);
            saveJobstoFile(user->jobs, file);
            fprintf(file, "EndUser\n");
            user = user->next;
        }
    }
    fclose(file);
}

Job* loadJobfromLine(char* line)
{
    char* title = strtok(line, ",");
    char* statusStr = strtok(NULL, ",");
    Job* job = malloc(sizeof(Job));
    strcpy(job->title, title);
    job->status = atoi(statusStr);
    job->left = job->right = NULL;
    return job;
}

void loadUserFromFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    char line[200];
    User* currentUser = NULL;

    while(fgets(line, sizeof(line), file))
    {
        line[strcspn(line, "\n")] = 0;
        if(strncmp(line, "User,", 5) == 0)
        {
            char* uname = strtok(line + 5, ",");
            char* pass = strtok(NULL, ",");
            registerUser(uname, pass);
            currentUser = findUser(uname);
        }
        else if(strcmp(line, "EndUser") == 0)
        {
            currentUser = NULL;
        }
        else if(currentUser)
        {
            Job* job = loadJobfromLine(line);
            currentUser->jobs = insertJob(currentUser->jobs, job->title);
            Job* j = searchJob(currentUser->jobs, job->title);
            if(j)
            {
                j->status = job->status;
                free(job);
            }
        }
    }
    fclose(file);
}
