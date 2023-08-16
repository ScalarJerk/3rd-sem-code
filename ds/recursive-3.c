// Recursive Multiplication using Repeated Addition

#include <stdio.h>

int recursiveMultiply(int a, int b) {
    if (b == 0)
        return 0;
    if (b > 0)
        return a + recursiveMultiply(a, b - 1);
    return -recursiveMultiply(a, -b);
}

int main() {
    int a = 5, b = 3;
    int result = recursiveMultiply(a, b);
    
    printf("%d * %d = %d\n", a, b, result);
    
    return 0;
}
