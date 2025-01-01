class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
        
        
solution = Solution()
s= "anagram"
t= "nagrama"
print(solution.isAnagram(s, t))          