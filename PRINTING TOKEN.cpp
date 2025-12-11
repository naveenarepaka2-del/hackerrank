#include <stdio.h>
#include <string.h>

int main() {
    char sentence[1000];   // buffer to hold the input sentence
    // Read the whole line including spaces
    fgets(sentence, sizeof(sentence), stdin);

    // Remove trailing newline if present
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
    }

    // Split sentence into words using space as delimiter
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        printf("%s\n", word);
        word = strtok(NULL, " ");
    }

    return 0;
}

