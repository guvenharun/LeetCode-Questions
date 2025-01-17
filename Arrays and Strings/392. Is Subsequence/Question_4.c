#include <stdio.h>
#include <stdbool.h>
#include <string.h>


bool isSubsequence(char* s, char*t) {
    int i =0, j=0;
    while (i < strlen(s) && j < strlen(t)) {

        if(s[i] == t[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    return i == strlen(s);
    
}

int main() {
    char *s = "abc";
    char *t = "ahbgdc";

    printf("%d", isSubsequence(s,t));

    return 0;
}

