from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique_nums=set(nums)
        return len(unique_nums) != len(nums)
solution = Solution()
nums = [1,2,3,4,1]
print(solution.containsDuplicate(nums))        
