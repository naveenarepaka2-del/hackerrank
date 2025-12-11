#include <stdio.h>
#include <stdlib.h>  // for malloc and free

int main() {
    int n;
    scanf("%d", &n);   // Read the size of the array

    // Dynamically allocate memory for n integers
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        // Always good to check if malloc succeeded
        printf("Memory allocation failed\n");
        return 1;
    }

    // Read n integers into the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // Print the result
    printf("%d\n", sum);

    // Free the allocated memory
    free(arr);

    return 0;
}

