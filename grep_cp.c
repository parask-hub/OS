
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int choice;
    pid_t pid;
    char file1[50], file2[50], search[50];
    do
    {
        // display menu
        printf("\nChoose an option:\n");
        printf("1. Copy a file\n");

        printf("2. Search for a word in a file\n");
        printf("3. List files in current directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // execute selected command
        switch (choice)
        {
        case 1:
            printf("Enter the source file name: ");
            scanf("%s", file1);
            printf("Enter the destination file name: ");
            scanf("%s", file2);
            pid = fork();
            if (pid == 0)
            {
                execl("/bin/cp", "cp", file1, file2, NULL);
                exit(0);
            }
            else
            {
                wait(NULL);
                printf("cp command completed\n");
            }
            break;
        case 2:
            printf("Enter the file name to search: ");
            scanf("%s", file1);
            printf("Enter the word to search for: ");
            scanf("%s", search);
            pid = fork();
            if (pid == 0)
            {
                execl("/bin/grep", "grep", search, file1, NULL);
                exit(0);
            }
            else
            {
                wait(NULL);
                printf("grep command completed\n");
            }
            break;
        case 3:
            pid = fork();
            if (pid == 0)
            {
                execl("/bin/ls", "ls", "-l", NULL);
                exit(0);
            }
            else
            {
                wait(NULL);
                printf("ls command completed\n");
            }
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 4);
    // print process ID
    pid_t current_pid = getpid();
    printf("My process ID is %d\n", current_pid);
    return 0;
}
