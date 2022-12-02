#include<stdio.h>
#include <time.h>
void calculateWaitingTime(int processes[], int n, int burst_time[], int waitingTime[], int quantum) 
{ 
    int temp_burst_time[n], t=0; 
    for (int i = 0 ; i < n ; i++) {
        temp_burst_time[i] = burst_time[i]; 
	} 
    while (1) { 
        bool done = true; 
        for (int i=0 ; i<n; i++) { 
            if (temp_burst_time[i] > 0) { 
                done = false;
                if (temp_burst_time[i] > quantum) { 
                    t += quantum; 
                    temp_burst_time[i] -= quantum; 
                } else { 
                    t = t + temp_burst_time[i]; 
                    waitingTime[i] = t - burst_time[i]; 
                    temp_burst_time[i] = 0; 
                } 
            } 
        } 
        if (done == true) 
        break; 
    } 
} 
void printLine(int n) {
	for (int i=0; i<n; i++) {
		printf("-");
	}
}
void printGanttChart(int n, int burst_time[]) {
	printLine(125);
    printf("\n");
    for (int i = 0; i < n; i++) {
    	printf("| [P%d: %d]", (i+1), burst_time[i]);
    	for (int j = 0; j < burst_time[i] - 1; j++) {
    		printf(" ");
		}
	}
	printf("| \n");
	printLine(125);
	
}
void RR(int processes[], int n, int burst_time[], int quantum) { 
    int waitingTime[n], total_waitingTime = 0; 
    calculateWaitingTime(processes, n, burst_time, waitingTime, quantum); 
    
    printf("Processes \t Burst time \t Waiting time\n"); 
    
    for (int i=0; i<n; i++) 
    { 
        total_waitingTime = total_waitingTime + waitingTime[i]; 
        printf(" P%d \t\t %d \t\t %d \n", (i+1), burst_time[i], waitingTime[i]);
    } 
    int avgWaitingTime = (float)total_waitingTime / (float)n;
    printf("\n Average waiting time = %dms \n", avgWaitingTime);
	printf("\n Gantt chart \n");
    printGanttChart(n, burst_time);
	printf("\n\n"); 
} 
int giveBurstTime(int depth) {
	int sum = 0;
	clock_t start = clock();
    for (int i = 0; i < depth; ++i)
        for(int j = 0; j < depth; ++j)
            sum += 1;
    clock_t end = clock();
    
    return (int)(end - start);
}
int main() { 
    int processes[] = { 1, 2, 3, 4, 5}; 
    int n = sizeof processes / sizeof processes[0]; 
    int  burst_time[5];
    
    burst_time[0] = giveBurstTime(3500);
    burst_time[1] = giveBurstTime(4000);
    burst_time[2] = giveBurstTime(900);
    burst_time[3] = giveBurstTime(1350);
    burst_time[4] = giveBurstTime(1920);
    
    // Time quantum 
    int quantum = 2; 
    RR(processes, n, burst_time, quantum); 
    return 0; 
} 