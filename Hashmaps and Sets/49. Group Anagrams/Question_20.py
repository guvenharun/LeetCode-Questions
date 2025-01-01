from typing import List

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        result = []
        for i in range(len(strs)):
            if not any(sorted(strs[i]) == sorted(res[0]) for res in result):
                anagram_group=[]
                for j in range(len(strs)):
                    if sorted(strs[i]) == sorted(strs[j]):
                        anagram_group.append(strs[j]) 
                result.append(anagram_group)    
        return result 
solution = Solution()
strs =["eat","tea","tan","ate","nat","bat"]
print(solution.groupAnagrams(strs))         