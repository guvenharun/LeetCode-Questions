from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_dict = {}
        for index, num in enumerate(nums):
            result = target- num
            if result in num_dict:
                return [num_dict[result],index]
            num_dict[num] = index

    
        return[]
solution = Solution()
nums = [2, 7, 11, 15]
target = 9
print(solution.twoSum(nums,target))    