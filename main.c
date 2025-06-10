#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "user.h"
#include "job.h"
#include "fileio.h"

void jobMenu(User* user)
{
    int choice;
    char title[MAX_TITLE];
    while(1)
    {
        printf("\n---Job Menu---\n");
        printf("1. Add job\n");
        printf("2. Mark Job as Done\n");
        printf("3. Delete Job\n");
        printf("4. View Job\n");
        printf("5. Save and Exit\n");
        printf("Choice:");
        scanf("%d",&choice);
        getchar();

        switch(choice)
        {
            case 1:
                printf("Enter Job Title:");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title,"\n")] = 0;
                user->jobs = insertJob(user->jobs, title);
                break;
            case 2:
                printf("Enter Job Title to Mark As Done: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                markJobdone(user->jobs, title);
                break;
            case 3:
                printf("Enter Job Title To Delete: ");
                fgets(title, MAX_TITLE, stdin);
                title[strcspn(title, "\n")] = 0;
                user->jobs = deleteJob(user->jobs, title);
                break;
            case 4:
                printf("All Jobs: \n");
                inOrder(user->jobs);
                break;
            case 5:
                saveUserstoFile("Database.txt");
                printf("Data has been saved\n");
                return;
            default:
                printf("Invalid Choice\n");
        }
    }
}

int main()
{
    loadUserFromFile("Database.txt");
    char username[MAX_USER], password[MAX_USER];
    int option;
    printf("1. Register \n2. Login\nChoice: ");
    scanf("%d", &option);
    getchar();
    printf("Username: ");
    fgets(username, MAX_USER, stdin);
    username[strcspn(username, "\n")] = 0;
    printf("Password: ");
    fgets(password, MAX_USER, stdin);
    password[strcspn(password, "\n")] = 0;
    if (option == 1)
    {
        registration(username, password);
    }
    User* user = findUser(username);
    if(!user)
    {
        printf("User not found...Exiting\n");
        return 1;
    }
    jobMenu(user);
    return 0;
}
