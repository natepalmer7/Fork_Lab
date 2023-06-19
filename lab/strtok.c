#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
    char str[] = "This is a sentence.";
    char *pch;
    
    printf ("Splitting string \"%s\" into tokens:\n",str);
    pch = strtok(str," ,.-"); 
    
    while (pch != NULL) 
    {
        printf ("%s\n",pch);
        pch = strtok(NULL, " ,.-");
    }
    
    return 0;
}
