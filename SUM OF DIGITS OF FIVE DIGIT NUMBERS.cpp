#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);   // Read the 5-digit number
    
    int sum = 0;
    
    // Extract digits one by one
    sum += n % 10;   // last digit
    n /= 10;
    
    sum += n % 10;   // 2nd last digit
    n /= 10;
    
    sum += n % 10;   // 3rd digit
    n /= 10;
    
    sum += n % 10;   // 4th digit
    n /= 10;
    
    sum += n % 10;   // 5th digit
    
    printf("%d\n", sum);  // Print the sum
    
    return 0;
}


