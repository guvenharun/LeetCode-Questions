from typing import List
from collections import Counter
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        magazine_frekans=Counter(magazine)
        
        for char in ransomNote:
            if char in magazine_frekans and magazine_frekans[char]>0:
                magazine_frekans[char] += -1
            else:
                return False             
        return True

ransomNote = "bg"
magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj"

solution = Solution()
print(solution.canConstruct(ransomNote, magazine)) 

