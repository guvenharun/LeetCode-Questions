class Solution:
   
    def findClosestNumber(self, numbers: List[int]) -> int:
        closest = numbers[0]
        for x in numbers:
            if abs(x) < abs(closest):
                closest = x
                  
        if closest < 0 and abs(closest) in numbers:
            return abs(closest)      
        else:
            return closest
solution = Solution()
array = [1, 2, 4, 5, -1]
print(solution.findClosestNumber(array))