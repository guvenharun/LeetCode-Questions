from typing import List

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        result = []
        i=0
        
        while i < len(nums):
            start = nums[i]
            while i<len(nums)-1 and nums[i] == nums[i+1]-1:
                i+=1
                
            if start != nums[i]:
                result.append(str(start) +"->"+ str(nums[i])) 
            else:
                result.append(str(nums[i]))       
            i+=1    
        return result   
    
solution = Solution()

numbers = [0, 2, 3, 4, 6, 8, 9]

print(solution.summaryRanges(numbers))


