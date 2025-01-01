from typing import List

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        m = len(matrix)
        n = len(matrix[0])
        row,column = 0,0
        dRow,dColumn = 0,1
        result=[]
        
        visited = [[False] * n for _ in range(m)]  
        for _ in range(m * n):
            result.append(matrix[row][column])
            visited[row][column] = True
            newRow, newColumn = row + dRow, column + dColumn

            if not (0 <= newRow < m and 0 <= newColumn < n and not visited[newRow][newColumn]):
                dRow, dColumn = dColumn, -dRow 
            row, column = row + dRow, column + dColumn  

        return result
    
sol = Solution()
matrix = [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
print(sol.spiralOrder(matrix))
    
                    