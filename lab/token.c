#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

int main() {
    char input[1000];
    char *words[MAX_WORDS];
    int wordCount = 0;
    
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    
    
    char *token = strtok(input, " \t\n");
    
    while (token != NULL && wordCount < MAX_WORDS) {
        
        words[wordCount] = (char *)malloc(strlen(token) + 1);
        
      
        strcpy(words[wordCount], token);
        
        wordCount++;
        
        
        token = strtok(NULL, " \t\n");
    }
    
    
    printf("Words in the string:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
    }
    
    
    for (int i = 0; i < wordCount; i++) {
        free(words[i]);
    }
    
    return 0;
}
