#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd[2];
    int k = pipe(fd);
    if (pipe == -1)
    {
        printf("Something Goes Wrong ! ERROR OCCURED\n");
    }
    pid_t pid;
    pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        int x;
        printf("Child Process !\n");
        printf("Enter X : ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    }
    else
    {
        int y;
        close(fd[1]);
        printf("Parent Process !\n");
        read(fd[0], &y, sizeof(int));
        y = y * y;
        printf("Squared Value : %d", y);
        close(fd[0]);
    }
}