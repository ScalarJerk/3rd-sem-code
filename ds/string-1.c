/* perform following string operations without
using string handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring*/

#include <stdio.h>

int str_length(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

void str_concat(char *dest, char *src) {
    int dest_len = str_length(dest);
    while (*src != '\0') {
        *(dest + dest_len) = *src;
        dest_len++;
        src++;
    }
    *(dest + dest_len) = '\0';
}

int str_compare(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }
    return (*str1 - *str2);
}

void str_insert(char *str, char *sub_str, int pos) {
    int len = str_length(str);
    int sub_len = str_length(sub_str);

    for (int i = len; i >= pos; i--) {
        *(str + i + sub_len) = *(str + i);
    }

    for (int i = 0; i < sub_len; i++) {
        *(str + pos + i) = *(sub_str + i);
    }
}

void str_delete(char *str, int pos, int length) {
    int len = str_length(str);
    for (int i = pos; i <= len - length; i++) {
        *(str + i) = *(str + i + length);
    }
    *(str + len - length) = '\0';
}

int main() {
    char str1[100], str2[100], subStr[50];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    printf("Length of string 1: %d\n", str_length(str1));

    char concatStr[200];
    str_concat(concatStr, str1);
    str_concat(concatStr, str2);
    printf("Concatenated string: %s\n", concatStr);

    int comparisonResult = str_compare(str1, str2);
    if (comparisonResult < 0)
        printf("String 1 is less than String 2\n");
    else if (comparisonResult > 0)
        printf("String 1 is greater than String 2\n");
    else
        printf("String 1 is equal to String 2\n");

    printf("Enter a substring to insert: ");
    scanf("%s", subStr);
    int insertPos;
    printf("Enter the position to insert: ");
    scanf("%d", &insertPos);
    str_insert(str1, subStr, insertPos);
    printf("String after insertion: %s\n", str1);

    int deletePos, deleteLength;
    printf("Enter the position to delete from: ");
    scanf("%d", &deletePos);
    printf("Enter the length to delete: ");
    scanf("%d", &deleteLength);
    str_delete(str1, deletePos, deleteLength);
    printf("String after deletion: %s\n", str1);

    return 0;
}
