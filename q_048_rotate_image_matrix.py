class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        # Learn: Spend time to on boundary condition worth it
        # Note: Spend time to figure out Loop boundaries worth it; it's more efficient to figure it out before hand than troubleshooting problems
        N = len(matrix) - 1
        for i in range (0, N//2 + 1):
            for j in range (0, (N+1)//2):
                cache_elem = matrix[i][j]
                matrix[i][j] = matrix[N-j][i]
                matrix[N-j][i] = matrix[N-i][N-j]
                matrix[N-i][N-j] = matrix[j][N-i]
                matrix[j][N-i] = cache_elem
