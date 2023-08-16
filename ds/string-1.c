/* perform following string operations without 
using string handling functions:
a.) length of the string
b.) string concatenation
c.) string comparison
d.) to insert a sub string
e.) to delete a substring*/
  
  #include <stdio.h>

// Function to calculate the length of a string
int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

// Function to concatenate two strings
void stringConcatenate(char destination[], const char source[]) {
    int destLen = stringLength(destination);
    int i = 0;
    while (source[i] != '\0') {
        destination[destLen + i] = source[i];
        i++;
    }
    destination[destLen + i] = '\0';
}

// Function to compare two strings
int stringCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (str1[i] - str2[i]);
        }
        i++;
    }
    return (str1[i] - str2[i]);
}

// Function to insert a substring in a string
void stringInsert(char str[], const char subStr[], int pos) {
    int len = stringLength(str);
    int subLen = stringLength(subStr);
    
    for (int i = len; i >= pos; i--) {
        str[i + subLen] = str[i];
    }
    
    for (int i = 0; i < subLen; i++) {
        str[pos + i] = subStr[i];
    }
}

// Function to delete a substring from a string
void stringDelete(char str[], int pos, int length) {
    int len = stringLength(str);
    for (int i = pos; i <= len - length; i++) {
        str[i] = str[i + length];
    }
    str[len - length] = '\0';
}

int main() {
    char str1[100], str2[100], subStr[50];
    
    printf("Enter the first string: ");
    scanf("%s", str1);
    
    printf("Enter the second string: ");
    scanf("%s", str2);
    
    printf("Length of string 1: %d\n", stringLength(str1));
    
    char concatStr[200];
    stringConcatenate(concatStr, str1);
    stringConcatenate(concatStr, str2);
    printf("Concatenated string: %s\n", concatStr);
    
    int comparisonResult = stringCompare(str1, str2);
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
    stringInsert(str1, subStr, insertPos);
    printf("String after insertion: %s\n", str1);
    
    int deletePos, deleteLength;
    printf("Enter the position to delete from: ");
    scanf("%d", &deletePos);
    printf("Enter the length to delete: ");
    scanf("%d", &deleteLength);
    stringDelete(str1, deletePos, deleteLength);
    printf("String after deletion: %s\n", str1);
    
    return 0;
}
