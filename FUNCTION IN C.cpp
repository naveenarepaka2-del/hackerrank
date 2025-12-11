#include <stdio.h>

// Function to return maximum of two integers
int max_of_two(int x, int y) {
    return (x > y) ? x : y;
}

// Function to return maximum of four integers
int max_of_four(int a, int b, int c, int d) {
    int max1 = max_of_two(a, b);
    int max2 = max_of_two(c, d);
    return max_of_two(max1, max2);
}

int main() {
    int a, b, c, d;
    
    // Read four integers
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // Print the maximum
    printf("%d\n", max_of_four(a, b, c, d));
    
    return 0;
}

