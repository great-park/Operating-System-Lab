#include <windows.h> // win API
#include <stdio.h>
DWORD Sum; // ���� ������

DWORD WINAPI Summation(LPVOID Param) { /* The thread(child) will execute */
	DWORD Upper = *(DWORD*)Param;
	for (DWORD i=1; i<=Upper; i++){
		Sum += i;
	}
	return 0;
}

int main(int argc, char *argv[]) { // parent thread
	DWORD ThreadId; /* global data */
	HANDLE ThreadHandle;
	int Param;
	Param = atoi(argv[1]);

	ThreadHandle = CreateThread( /* create the thread */
	NULL, /* default security attributes */
	0, /* default stack size */
	Summation, /* thread function */
	&Param, /* parameter to thread function */
	0, /* default creation flags */
	&ThreadId); /* returns the thread identifier */

	WaitForSingleObject(ThreadHandle, INFINITE); /* wait for the thread to finish */
	CloseHandle(ThreadHandle); /* close the thread handle */
	printf("sum = %d?n", Sum); // child ���� ��child �� �����sum ���
}
