#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

#define MAX_TITLE 100

typedef struct Job
{
    char title[MAX_TITLE];
    int status;
    struct Job* left;
    struct Job* right;
} Job;

Job* insertJob(Job* root, char* title);
Job* searchJob(Job* root, char* title);
void markJobdone(Job* root, char* title);
void inOrder(Job* root);
Job* deleteJob(Job* root, char* title);
Job* minValueNode(Job* node);

#endif
