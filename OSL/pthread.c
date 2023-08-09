#include <pthread.h>
#include <stdio.h>

void *compute(void *add){
    long *add_num = (long *)(add);
    printf("Add %ld\n", *add_num);
    return NULL;
}

int main(){
    pthread_t thread1;
    pthread_t thread2;
    long value1 = 4;
    pthread_create(&thread1, NULL, compute, (void *) &value1);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, compute, (void *) &value1);
pthread_join(thread2, NULL);
    return 0;
}