#include <stdio.h>

int main() {
    char s[1000];   // buffer to store input string
    
    // Read a line of text from stdin
    fgets(s, sizeof(s), stdin);
    
    // Print "Hello, World!" on the first line
    printf("Hello, World!\n");
    
    // Print the input string on the next line
    printf("%s", s);
    
    return 0;
}

