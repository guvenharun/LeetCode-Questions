from typing import List

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda interval: interval[0]) 
        result = []
        for interval in intervals:
            if result and result[-1][1] >= interval[0]:
                result[-1] = [result[-1][0],max(result[-1][1],interval[1])]
            else:
                result.append(interval)
        return result             
                               

sol = Solution()
intervals = [[1,3],[2,6],[8,10],[15,18]]
print(sol.merge(intervals))
