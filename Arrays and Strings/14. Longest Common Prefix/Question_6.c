#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  

    int n = 0;  
    int m = 0; 

    char* result = (char*)malloc(1000 * sizeof(char));
    if (!result) return NULL; 
    memset(result, 0, 1000 * sizeof(char));  

    while (1) {
        char current = strs[0][m];
        if (current == '\0') { 
            result[m] = '\0';
            break;
        }

        if (n < strsSize - 1) {
            if (m >= strlen(strs[n + 1]) || strs[n + 1][m] != current || current == '\0') {
                result[m] = '\0';  
                break;
            }
            n++;
            
        } else {
            result[m] = current;  
            m++;  
            n = 0;  
        }
    }

    return result; 
}

int main() {
    char* strs1[] = {"flower", "flow", "flight"};
    char* strs2[] = {"dog", "racecar", "car"};

    char* result1 = longestCommonPrefix(strs1, 3);
    printf("result 1: '%s'\n", result1);
    free(result1);

    char* result2 = longestCommonPrefix(strs2, 3);
    printf("result 2: '%s'\n", result2);
    free(result2);

    return 0;
}
