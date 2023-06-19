#include <stdio.h>

int main (int argc, char *argv[]) {
    int pid = fork();
    
    if ( pid == 0 ) {
        printf( "This is being printed from the child process\n" );
    }
    
    else {
        printf( "This is being printed in the parent process:\n"
        " - the process identifier (pid) of the child is %d\n", pid);
        
        
        printf( "This is being printed in the parent process:\n"
        " - the process identifier (pid) of the parent is %d\n", (int) getpid());
    }
    
    return 0;
}