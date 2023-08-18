
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

void sortArray(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pid_t pid = fork();
    if (pid < 0)
    {
        fprintf(stderr, "Fork failed\n");
        return 1;
    }
    else if (pid == 0)
    {

        // Child process
        printf("\nMain process start: (pid) %d\n", getpid());
        sortArray(arr, n);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        char *args[n + 2];
        args[0] = "./c";
        for (int i = 0; i < n; i++)
        {
            char buffer[10];
            snprintf(buffer, sizeof(buffer), "%d", arr[i]); // converts int to string format and pass them into the buffer
            args[i + 1] = strdup(buffer);                   // strdup:- (string duplicate) create a new copy of the string
        }
        args[n + 1] = NULL; // indicate the end of the list of command-line arguments.

        execve(args[0], args, NULL);
        perror("execve");
        printf("Main process end: (pid) %d\n", getpid());
        return 1;
    }
    else
    {
        // Parent process wait(NULL);
        printf("\nParent process finished.\n");
    }

    return 0;
}
