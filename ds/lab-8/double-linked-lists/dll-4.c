/*Write a program to implement 
addition of two long positive integer numbers. */
  
  #include <stdio.h>
#include <string.h>

#define MAX_DIGITS 1000

void addLongIntegers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        
        result[k++] = (sum % 10) + '0';

        i--;
        j--;
    }
    
    result[k] = '\0';

    // Reverse the result string
    int start = 0;
    int end = k - 1;
    while (start < end) {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char num1[MAX_DIGITS];
    char num2[MAX_DIGITS];
    char result[MAX_DIGITS + 1];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);

    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    addLongIntegers(num1, num2, result);

    printf("Sum: %s\n", result);

    return 0;
}
