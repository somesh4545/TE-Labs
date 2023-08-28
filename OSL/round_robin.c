#include <stdio.h>
#include <stdlib.h>
#define MAX 10

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int cmpbyarrivaltime( const void *pa, const void *pb ) {
    const int (*a)[7] = pa;
    const int (*b)[7] = pb;
    if ( (*a)[1] < (*b)[1] ) return -1;
    if ( (*a)[1] > (*b)[1] ) return +1;
    return 0;
}

// [0] id [1] AT [2] BT [3] CT [4] TAT [5] WT [6] remaining time

void os_rr(int process[MAX][7], int n, int col, int time_q){
    int i=0, j=0;
    int ct=process[0][1], tat=0, wt=0;
    
    int total_time = 0;
    for(i=0; i<n; i++) total_time += process[i][2];
    
    printf("\n\nPID\tAT\tBt\tCT\tTaT\tWT\n");
    int count = 0;
    int t_tat=0, t_wt=0, index=0;
    for(i=0; i<total_time;){
        while(process[index][6]==0) index  = (index+1)%n;
        
        int val = time_q < process[index][6] ? time_q : process[index][6];
        i+= val;
        process[index][6] -= val;

        if(process[index][6] == 0){
            count++;
            process[index][3] = i;
            process[index][4] = i-process[index][1];
            t_tat+=process[index][4];
            process[index][5] = process[index][4] - process[index][2];
            t_wt += process[index][5];
        }
        if(count==n) break;
        index  = (index+1)%n;
    }

    for(i=0; i<n; i++){
        for(j=0; j<6; j++)
            printf("%d\t",process[i][j]); 
        printf("\n");
    }
    
    float avg_tat = (float)t_tat/n;
    float avg_wt = (float)t_wt/n;
    printf("\n\nStats\n");
    printf("Avg TAT: %f\n", avg_tat);
    printf("Avg WT: %f\n", avg_wt);
}
 
int main ( ) {
    int process[MAX][7];
    
    int n;
    printf("Enter number of process: ");
    scanf("%d", &n);

    int time_q;
    printf("Enter time quantam: ");
    scanf("%d", &time_q);

    int i = 0;
    printf("Enter the process id: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][0]);
    }
    printf("Enter the arrival time: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][1]);
    }
    printf("Enter the burst time: ");
    for(i=0; i<n; i++){
        scanf("%d", &process[i][2]);
        process[i][6] = process[i][2];
    }
    qsort(process, n, sizeof(process[0]), cmpbyarrivaltime);
    os_rr(process, n, 6, time_q);

    return 0;
}