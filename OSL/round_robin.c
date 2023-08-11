#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int cmpbyarrivaltime( const void *pa, const void *pb ) {
    const int (*a)[6] = pa;
    const int (*b)[6] = pb;
    if ( (*a)[2] < (*b)[2] ) return -1;
    if ( (*a)[2] > (*b)[2] ) return +1;
    return 0;
}

void os_rr(int process[MAX][7], int n, int col, int time_q){
    int i=0, j=0;
    int ct=process[0][1], tat=0, wt=0;
    
    int total_time = 0;
    for(i=0; i<n; i++) total_time += process[i][2];
    
    printf("\n\nPID\tAT\tBt\tCT\tTaT\tWT\tRT\n");
    int t_tat=0, t_wt=0;
    for(i=0; i<n;){
        
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
    }
    qsort(process, n, sizeof(process[0]), cmpbyarrivaltime);
    os_rr(process, n, 6, time_q);

    return 0;
}