from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [1] * n
        right,left= 1,1
        
        for i in range(n):
            result[i] = left
            left *= nums[i]

       
        for i in range(n - 1, -1, -1):
            result[i] *= right
            right*= nums[i]

        return result
        
solution = Solution()

numbers, numbersTwo,numbersThree = [1,2,3,4],[-1,1,0,-3,3],[0,0]


print(solution.productExceptSelf(numbers))       
print(solution.productExceptSelf(numbersTwo))       
print(solution.productExceptSelf(numbersThree))      