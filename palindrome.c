#include <stdio.h>
#include <string.h>

int Palindromecheck(char* str, int n) {
    char word1[10], word2[10];
    int i = 0;
    for (i = 0; i < n/2; i++) {
        word1[i] = str[i];
    } word1[i] = '\0';
    for (i = 0; i < n/2; i++) {
        word2[i] = str[n-i-1];
    } word2[i] = '\0';
    return strcmp(word1, word2);
}

int main() {
    int n;
    char ipword[20];
    char opword[15][20];
    char *nagation[15];

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", ipword);
        strcpy(opword[i], ipword);
        nagation[i] = (Palindromecheck(ipword, strlen(ipword))==0)?"":"Not ";
    }
    
    for (int i = 0; i < n; i++) {
        printf("%s Is %sPalindrome.\n", opword[i], nagation[i]);
    }
}