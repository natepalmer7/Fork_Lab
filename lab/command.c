#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 64

int main() {
    char command[MAX_COMMAND_LENGTH];
    
    while (1) {
        // Prompt the user to enter a command
        printf("Enter a Unix command (or 'DONE' to exit): ");
        fgets(command, sizeof(command), stdin);
        
        // Remove the trailing newline character from the command
        command[strcspn(command, "\n")] = '\0';
        
        // Check if the user wants to exit
        if (strcmp(command, "DONE") == 0) {
            break;
        }
        
        // Fork a child process
        pid_t pid = fork();
        
        if (pid < 0) {
            // Forking failed
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            // Execute the command using the shell
            execlp("/bin/sh", "sh", "-c", command, NULL);
            
            // If execlp returns, it means an error occurred
            perror("Command execution failed");
            exit(1);
        } else {
            // Parent process
            // Wait for the child process to finish
            int status;
            waitpid(pid, &status, 0);
            
            // Report the exit status
            if (WIFEXITED(status)) {
                printf("Command exited with status: %d\n", WEXITSTATUS(status));
            } else {
                printf("Command terminated abnormally\n");
            }
        }
    }
    
    return 0;
}
