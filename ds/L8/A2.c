#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main() {
    char str1[MAX_LEN], str2[MAX_LEN], result[MAX_LEN];
    int carry = 0, i, j, k;

    printf("Enter the first number: ");
    scanf("%s", str1);

    printf("Enter the second number: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Reverse the strings
    for (i = 0, j = len1 - 1; i < len1 / 2; i++, j--) {
        char temp = str1[i];
        str1[i] = str1[j];
        str1[j] = temp;
    }

    for (i = 0, j = len2 - 1; i < len2 / 2; i++, j--) {
        char temp = str2[i];
        str2[i] = str2[j];
        str2[j] = temp;
    }

    // Add the numbers
    for (i = 0; i < len1 || i < len2; i++) {
        int digit1 = i < len1 ? str1[i] - '0' : 0;
        int digit2 = i < len2 ? str2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        result[i] = sum % 10 + '0';
        carry = sum / 10;
    }

    if (carry > 0) {
        result[i++] = carry + '0';
    }

    // Reverse the result
    for (j = 0, k = i - 1; j < k; j++, k--) {
        char temp = result[j];
        result[j] = result[k];
        result[k] = temp;
    }

    printf("The sum of the two numbers is: %s\n", result);

    return 0;
}
