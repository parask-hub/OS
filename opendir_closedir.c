#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    DIR *dir;
    struct dirent *entry;
    char dirname[100];
    int ch = 1;
    do
    {
        // display menu
        printf("\nChoose an option:\n");
        printf("1. List files in current directory\n");
        printf("2. List files in a directory\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            // open the current directory
            dir = opendir(".");
            // check if the directory was opened successfully
            if (dir == NULL)
            {
                printf("Error opening directory\n");
                break;
            }
            // read and print the directory entries
            while ((entry = readdir(dir)) != NULL)
            {
                printf("%s\n", entry->d_name);
            }
            // close the directory
            closedir(dir);
            break;
        case 2:
            printf("Enter the directory name: ");
            scanf("%s", dirname);
            // open the specified directory
            dir = opendir(dirname);
            // check if the directory was opened successfully
            if (dir == NULL)
            {
                printf("Error opening directory\n");
                break;
            }
            // read and print the directory entries
            while ((entry = readdir(dir)) != NULL)
            {
                printf("%s\n", entry->d_name);
            }
            // close the directory
            closedir(dir);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (ch != 3);
    return 0;
}
