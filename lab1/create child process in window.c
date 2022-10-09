#include <windows.h>
#include <stdio.h>

int main(void)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
    ZeroMemory( &si, sizeof(si) );
    si.cb = sizeof(si);
    ZeroMemory( &pi, sizeof(pi) );

    if( !CreateProcess( NULL,   
        "C:\\Windows\\System32\\calc.exe",  //기본 계산기 실행 
        NULL,           
        NULL,           
        FALSE,         
        0,              
        NULL,          
        NULL,           
        &si, &pi )) 
    {
        fprintf( stderr, "CreateProcess failed");
        return -1;
    }

    WaitForSingleObject( pi.hProcess, INFINITE );
	printf("Child Complete");
 
    CloseHandle( pi.hProcess );
    CloseHandle( pi.hThread );
}
