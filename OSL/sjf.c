#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// Enter the process id: 1 2 3 4 5
// Enter the arrival time: 2 5 1 0 4
// Enter the burst time: 6 2 8 3 4

void os_sjf(int process[MAX][8], int n, int col, int start_time, int total_time){
    int i=0, j=0;
    int ct=process[0][1], tat=0, wt=0;
    int t_tat=0, t_wt=0;
    for(i=start_time; i<=total_time; i++){


        // finding the process which has lower arrival time + bt 
        // [1] arrival time [2] burst time [3] remaining execution
        int index = 0;
        while(index<n && process[index][1]>i && process[index][3]!=0) index++;
        // printf("\n%d\n", index);
        for(j=0; j<n; j++){
            if(j==index || process[j][7]>i) continue;
            if(i==5 && j==1){
                printf("\n%d %d\n", process[j][1], process[index][1]);
                printf("\%d\n", (process[j][1]<=process[index][1]));
            } 
            if(process[j][3] < process[index][3] && process[j][1]<=process[index][1]  && process[j][3]!=0)
                index = j;
        }
        printf("\n%d - %d",i+1, index+1);
        process[index][1] = i+1;
        process[index][3] -= 1;
        if(process[index][3]==0){
            // [4] CT [5] TAT [6] WT
            process[index][4] = i+1;
            process[index][5] = i+1 - process[index][7];
            process[index][6] = process[index][5] - process[index][2];
        }
    }
    printf("\n\nPID\tAT\tBt\tCT\tTaT\tWT\n");
    for(i=0; i<n; i++){
        for(j=0; j<8; j++)
            if(j==1) 
                printf("%d\t",process[i][7]); 
            else if(j!=3 && j!=7)
                printf("%d\t",process[i][j]); 
        printf("\n");
    }
    // float avg_tat = (float)t_tat/n;
    // float avg_wt = (float)t_wt/n;
    // printf("\n\nStats\n");
    // printf("Avg TAT: %f\n", avg_tat);
    // printf("Avg WT: %f\n", avg_wt);
}
 
int main ( ) {
    // [1] arrival time [2] burst time [3] remaining execution
    // [4] CT [5] TAT [6] WT [7] original at
    int process[MAX][8];
    
    int n;
    printf("Enter number of process: ");
    scanf("%d", &n);

    int i = 0, total_time=100;
    printf("Enter the process id: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][0]);
    }
    printf("Enter the arrival time: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][1]);
        process[i][7] = process[i][1];
        total_time = total_time<process[i][1] ? total_time : process[i][1];
    }
    int start_time = total_time;
    printf("Enter the burst time: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][2]);
        total_time += process[i][2];
        process[i][3] = process[i][2];
    }
    
    os_sjf(process, n, 8, start_time, total_time);

    return 0;
}