#include<stdio.h>
void calculateWaitingTime(int processes[], int n, int burst_time[], int waitingTime[])
{
    waitingTime[0] = 0;
   
    for (int  i = 1; i < n ; i++ )
        waitingTime[i] =  burst_time[i-1] + waitingTime[i-1] ;
}

void printLine(int n) {
	for (int i=0; i<n; i++) {
		printf("-");
	}
}

void printGanttChart(int n, int burst_time[]) {
	printLine(105);
    printf("\n");
    for (int i = 0; i < n; i++) {
    	printf("| [P%d: %d]", (i+1), burst_time[i]);
    	for (int j = 0; j < burst_time[i] - 1; j++) {
    		printf(" ");
		}
		
	}
	printf("| \n");
	printLine(105);
	
}
   
void FCFS( int processes[], int n, int burst_time[]) {
    int waitingTime[n], total_waitingTime = 0;
   
    calculateWaitingTime(processes, n, burst_time, waitingTime);
    printf("Processes \t Burst time \t Waiting time\n");
   
    for (int  i=0; i<n; i++) {
        total_waitingTime = total_waitingTime + waitingTime[i];
        printf(" P%d \t\t %d \t\t %d \n", (i+1), burst_time[i], waitingTime[i]);
    }
    int avgWaitingTime = (float)total_waitingTime / (float)n;
    
    printf("\n Average waiting time = %dms \n", avgWaitingTime);
    printf("\n Gantt chart \n");
    printGanttChart(n, burst_time);
	printf("\n\n");
}
   
int main() {
    int processes[] = { 1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];
    int  burst_time[] = {10, 29, 3, 7, 12};
   
    FCFS(processes, n,  burst_time);
    
    return 0;
}