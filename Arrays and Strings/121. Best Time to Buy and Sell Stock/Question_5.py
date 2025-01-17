class Solution:
    def maxProfit(self, prices):
  
        current = 0
        prev = 0
        higher=0
        index = []
        lower=prices[0]
        for i in range(len(prices)):
            current = prices[i]            
            if current< prev:
                if current< lower:
                    lower = current
                    higher = 0
                    
            else:
                higher = current                   
            prev = current   
            index.append(higher-lower)    
                
        if  max(index)  > 0:
            return  max(index)   
        else:
            return 0
    
solution = Solution()
prices=[1,2]
print(solution.maxProfit(prices))  
