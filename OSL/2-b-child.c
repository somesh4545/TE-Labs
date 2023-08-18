// CHILD PROCESS
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid = fork();
    printf("Child process start: (pid) %d\n", getpid());
    printf("Array in reverse order: ");
    for (int i = argc - 1; i > 0; i--)
    {
        printf("%s ", argv[i]);
    }
    printf("\n");
    printf("Child process start: (pid) %d\n", getpid());
    return 0;
}
