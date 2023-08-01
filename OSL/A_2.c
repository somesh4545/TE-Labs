#include<stdio.h>
#include<unistd.h>
 #include <math.h>

int main(){
    int a=0;
    printf("Parent Process ID: %d\n", getppid());
    printf("Enter number of child process you want: ");
    scanf("%d", &a);
    a+=1;
    while(ceil(log2(a)) != floor(log2(a))){
        printf("Invalid number provided, Try again \n");
        printf("Enter number of child process you want: ");
        scanf("%d", &a);
        a+=1;
    }
    printf("\n\n");
    int i;
    for(i=0; i<(int)log2(a); i++){
        fork();
        if(i==((int)log2(a))-1){
            printf("Leaf Node pid: %d\n", getpid());
        }else{
            printf("Intermidate Node pid: %d\n", getpid());
        }
        sleep(2);
        // sleep()
    }
    sleep(5);
    printf("Fork call: %d\n", i+1);

    return 0;
}