from typing import List

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        arr_current = strs[0]  
        arr_result = ""
        j = 0
        
        while j < len(arr_current):
            for k in range(len(strs)):          
                if j >= len(strs[k]) or strs[k][j] != arr_current[j]:
                    return arr_result
            
            arr_result += arr_current[j]
            j += 1
        
        return arr_result
sol = Solution()
strs = ["ab", "a"]
print(sol.longestCommonPrefix(strs))  
