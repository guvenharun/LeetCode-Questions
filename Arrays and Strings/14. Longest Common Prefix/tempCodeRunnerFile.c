char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  

    int n = 0;  
    int m = 0; 

    char* result = (char*)malloc(1000 * sizeof(char));
    if (!result) return NULL; 
    memset(result, 0, 1000 * sizeof(char));  

    while (1) {
 
        if (n == 0 && strsSize > 1 && strs[0][0] != strs[1][0]) {
            result[0] = '\0'; 
            return result;
        }
        char current = strs[0][m];


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