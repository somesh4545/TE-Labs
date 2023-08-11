#include <stdio.h>
#include <stdlib.h>
#define MAX 10
// Enter the process id: 1 2 3 4 5
// Enter the arrival time: 2 5 1 0 4
// Enter the burst time: 6 2 8 3 4
int cmpbybursttime( const void *pa, const void *pb ) {
    const int (*a)[6] = pa;
    const int (*b)[6] = pb;
    if ( (*a)[1] < (*b)[1]) return -1;
    if ( (*a)[1] == (*b)[1] && (*a)[2] < (*b)[2]) return -1;
    if ( (*a)[1] == (*b)[1] && (*a)[2] > (*b)[2]) return 1;
    if ( (*a)[1] > (*b)[1]) return +1;
    return 0;
}

void os_sjf(int process[MAX][6], int n, int col){
    int i=0, j=0;
    int ct=process[0][1], tat=0, wt=0;
    printf("\n\nPID\tAT\tBt\tCT\tTaT\tWT\n");
    int t_tat=0, t_wt=0;
    for(i=0; i<n; i++){
        ct += process[i][2];
        process[i][3] = ct;
        tat = ct - process[i][1];
        process[i][4] = tat;
        wt = tat - process[i][2];
        process[i][5] = wt;
        t_tat += tat;
        t_wt += wt;
        for(j=0; j<col; j++){
            printf("%d\t", process[i][j]);
        }
        printf("\n");
    }
    float avg_tat = (float)t_tat/n;
    float avg_wt = (float)t_wt/n;
    printf("\n\nStats\n");
    printf("Avg TAT: %f\n", avg_tat);
    printf("Avg WT: %f\n", avg_wt);
}
 
int main ( ) {
    int process[MAX][6];
    
    int n;
    printf("Enter number of process: ");
    scanf("%d", &n);

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

    qsort( process, n, sizeof process[0], cmpbybursttime );
    
    os_sjf(process, n, 6);

    return 0;
}