#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);

    int i = 0, j = 0, counter = 0;

    char *result = (char *)malloc(len1+len2+1);

    while (i<len1 || j < len2){
        if (i < len1) {
            result[counter++] = word1[i++];
        }
        if (j < len2) {
            result[counter++] = word2[j++];
        }
        
       
    }
    result[counter] = '\0';
    return result;
}

int main() {
    char *word1 = "abc";
    char *word2 = "1234";
    char *merged = mergeAlternately(word1, word2);
    

    printf(" %s", merged);
    free(merged);
    
    
    return 0;
}