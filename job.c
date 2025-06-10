#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "job.h"

Job* insertJob(Job* root, char* title)
{
    if(!root)
    {
        Job* newJob = (Job*)malloc(sizeof(Job));
        strcpy(newJob->title, title);
        newJob->status = 0;
        newJob->left = newJob->right = NULL;
        return newJob;
    }
    if(strcmp(title, root->title) < 0)
    {
        root->left = insertJob(root->left, title);
    }
    else if(strcmp(title, root->title) > 0)
    {
        root->right = insertJob(root->right, title);
    }
    return root;
}

Job* searchJob(Job* root, char* title)
{
    if(!root || strcmp(title, root->title) == 0)
        return root;
    if(strcmp(title, root->title) < 0)
        return searchJob(root->left, title);
    return searchJob(root->right, title);
}

void markJobdone(Job* root, char* title)
{
    Job* job = searchJob(root, title);
    if(job)
        job->status = 1;
}

void inOrder(Job* root)
{
    if(!root)
        return;
    inOrder(root->left);
    printf("%s [%s]\n",root->title, root->status ? "Done" : "Pending");
    inOrder(root->right);
}

Job* minValueNode(Job* node)
{
    Job* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

Job* deleteJob(Job* root, char* title)
{
    if(!root)
        return NULL;
    if(strcmp(title, root->title) < 0)
        root->left = deleteJob(root->left, title);
    else if(strcmp(title, root->title) > 0)
        root->right = deleteJob(root->right, title);
    else
    {
        if(!root->left)
        {
            Job* temp = root->right;
            free(root);
            return temp;
        }
        else if(!root->right)
        {
            Job* temp = root->left;
            free(root);
            return temp;
        }
        Job* temp = minValueNode(root->right);
        strcpy(root->title, temp->title);
        root->status = temp->status;
        root->right = deleteJob(root->right, temp->title);
    }
    return root;
}
