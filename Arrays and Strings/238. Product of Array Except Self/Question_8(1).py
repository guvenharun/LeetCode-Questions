from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        i ,current=0, 0
        result=[]
        res= 1
        
        while i < len(nums):
            current = i
            for j in range(len(nums)):
               if current != j:
                   res *=nums[j]
            result.append(int(res))
            res=1
            i+=1
        return result    
        
solution = Solution()

numbers, numbersTwo,numbersThree = [1,2,3,4],[-1,1,0,-3,3],[0,0]


print(solution.productExceptSelf(numbers))       
print(solution.productExceptSelf(numbersTwo))       
print(solution.productExceptSelf(numbersThree))      