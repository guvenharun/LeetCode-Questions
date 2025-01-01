from typing import List

class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        return sum(map(stones.count,list(jewels)))
    
solution = Solution()
jewels ="aA"
stones ="aAAbbbb"
print(solution.numJewelsInStones(jewels,stones))
 