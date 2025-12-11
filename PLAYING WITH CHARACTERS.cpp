#include <stdio.h>

int main() {
    char ch;
    char str[100];
    char sentence[100];
    
    // Read a character
    scanf("%c", &ch);
    
    // Read a string (word without spaces)
    scanf("%s", str);
    
    // Read a sentence (with spaces)
    scanf("\n");  // consume the newline left by previous input
    scanf("%[^\n]%*c", sentence);
    
    // Print outputs
    printf("%c\n", ch);
    printf("%s\n", str);
    printf("%s\n", sentence);
    
    return 0;
}

