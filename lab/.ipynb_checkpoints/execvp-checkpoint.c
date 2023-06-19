 #include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
    char *args[3]; // main arg for child proc
    
    args[0] = "ls";
    args[1] = "-l";
    args[2] = NULL; 
    
    pid_t pid = fork();
    if ( pid == (pid_t) 0 ) { // child process
        if (execvp(args[0], args) == -1) { // this reporst if error occurs
            perror("execvp: error");
        }

       
        exit(1);
    }
    
    else {
        if (pid == (pid_t) (-1)) { 
            perror("Fork failed");
            exit(1);
        }
        
        int cstatus;
        pid_t c = wait(&cstatus); 
        printf("Parent: Child %ld exited with status = %d\n", (long) c, cstatus);
    }
    return 0;
}