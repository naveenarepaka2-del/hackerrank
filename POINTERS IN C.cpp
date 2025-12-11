#include <stdio.h>
#include <stdlib.h>  // for abs()

// Function to update values using pointers
void update(int *a, int *b) {
    int tempA = *a;
    int tempB = *b;
    
    *a = tempA + tempB;           // sum
    *b = abs(tempA - tempB);      // absolute difference
}

int main() {
    int a, b;
    
    // Read two integers
    scanf("%d %d", &a, &b);
    
    // Call update function
    update(&a, &b);
    
    // Print updated values
    printf("%d\n%d\n", a, b);
    
    return 0;
}

