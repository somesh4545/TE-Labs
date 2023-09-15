// Implement C program to demonstrate producer-consumer problem with
// counting semaphores and mutex.

#include <stdio.h>
#include <stdlib.h>

int mutex=1;
int full=0;
int empty=5;
int x = 0;

void producer(){
    mutex--;
    full++;
    empty--;
    x++;
    printf("Producer produces item: %d\n", x);
    mutex++;
}

void consumer(){
    mutex--;
    full--;
    empty++;
    printf("Consumer consumes item: %d\n", x);
    x--;
    mutex++;
}

int main ( ) {
    printf("1.Press 1 for producer\n2.Press 2 for consume\n3.Press 3 for exit.\n");
    int i, n;

    #pragma omp critical 
    for(i=1; i>=1; i++){
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            if(mutex==1 && empty!=0) producer();
            else printf("Buffer is full\n");
            break;
        case 2:
            if(mutex==1 && full!=0) consumer();
            else printf("Buffer is empty\n");
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option selected\n");
            break;
        }
    }

    return 0;
}