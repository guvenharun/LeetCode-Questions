from collections import Counter
class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        s_frekans = Counter(text)
        balloon_frekans = Counter("balloon")

        counter = float('inf')

        for char in balloon_frekans:
            if char in s_frekans:
                counter = min(counter, s_frekans[char] // balloon_frekans[char])
            else:
                return 0

        return counter
solution = Solution()
print(solution.maxNumberOfBalloons("nlaebolkoballoon")) 
print(solution.maxNumberOfBalloons("lloo"))  

