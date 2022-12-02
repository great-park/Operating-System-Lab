#include <stdio.h>
#include <time.h>
int giveBurstTime(int depth) {
	int sum = 0;
	clock_t start = clock();
    for (int i = 0; i < depth; ++i)
        for(int j = 0; j < depth; ++j)
            sum += 1;
    clock_t end = clock();
    
    return (int)(end - start);
}
void printLine(int n) {
	for (int i=0; i<n; i++) {
		printf("-");
	}
}
void printGanttChart(int n, int A[100][3]) {
	printLine(90);
    printf("\n");
    for (int i = 0; i < n; i++) {
    	printf("| [P%d: %d]", (i+1), A[i][1]);
    	for (int j = 0; j < A[i][1] - 1; j++) {
    		printf(" ");
		}
	}
	printf("| \n");
	printLine(90);
	
}
int main()
{
    int A[100][3]; 
    int i, j, index, temp;
    int n=5, total=0;
    float avg_waitingTime;
    int depth[5] = {1400,2300,900,3300,600};
    
    for (i = 0; i < n; i++) {
    	A[i][1] = giveBurstTime(depth[i]);
        A[i][0] = i + 1;
    }
    
    for (i = 0; i < n; i++) {
        index = i;
        for (j = i + 1; j < n; j++){
        	if (A[j][1] < A[index][1]){
        		index = j;
			}
		}
		
        temp = A[i][1];
        A[i][1] = A[index][1];
        A[index][1] = temp;
 
        
        temp = A[i][0];
        A[i][0] = A[index][0];
        A[index][0] = temp;
    }
    A[0][2] = 0;

    for (i = 1; i < n; i++) {
        A[i][2] = 0;
        for (j = 0; j < i; j++)
            A[i][2] += A[j][1];
        total += A[i][2];
    }
    
    avg_waitingTime = (float)total / n;
    total = 0;
    printf("P \t Brust Time \t Waiting Time \n");
    for (i = 0; i < n; i++) {
        printf("P%d \t\t %d \t\t %d\n", A[i][0], A[i][1], A[i][2]);
    }
    printf("\nAverage Waiting Time= %f \n", avg_waitingTime);
    printf("\n Gantt chart \n");
    printGanttChart(n, A);
    printf("\n\n");
}