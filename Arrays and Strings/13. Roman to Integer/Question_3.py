class Solution:
    def romanToInt(self, s: str) -> int:
        sum = 0
        roman_values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        prev_value = 0
        
        for i in range(len(s)):
            current_value = roman_values[s[i]]
            
            if current_value > prev_value:
                sum += current_value-2*prev_value
            else:
                sum += current_value
            
            prev_value = current_value
        
        return sum
solution = Solution()
s = "MCMXCIV"  
print(solution.romanToInt(s))
