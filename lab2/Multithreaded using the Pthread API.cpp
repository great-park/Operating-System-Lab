#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

int sum; /* global data shared by the thread(s) */
void *runner(void *param); /* threads call this function */

int main(int argc, char *argv[]) { /* a single thread(parent) of control begins */
	pthread_ t workers[NUM_THREADS]; /* the thread identifier */
	pthread_attr_t attr; /* set of thread attributes */

	pthread_attr_init(&attr); /* set the default attributes of the thread */
	pthread_create(&workers[0], &attr, runner, argv[1]); /* create a second thread */

	for (int i=0; i<NUM_THREADS; i++){
		pthread_join(workers[i], NULL); /* wait for the thread to exit */
	}	

	printf("sum = %d?n", sum);
}

void *runner(void *param) { /* The thread(child) will execute */
	int i, upper=atoi(param);
	sum=0;

	for (i=1; i< upper; i++){
		sum += i;
	}
	pthread_exit(0);
}
