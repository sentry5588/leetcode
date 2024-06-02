class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row_num, col_num = len(matrix), len(matrix[0])
        # print(f"{row_num=} {col_num=}")
        
        # Record first row/col result
        first_row = 1
        first_col = 1
        for i in range(0, row_num):
            if matrix[i][0] == 0:
                first_col = 0
                break
        for j in range(0, col_num):
            if matrix[0][j] == 0:
                first_row = 0
                break
        
        # use first row/col as row/col indicators
        for i in range(1, row_num):
            for j in range(1, col_num):
                if matrix[i][j] == 0:
                    matrix[i][0] = 0
                    matrix[0][j] = 0
        
        # use first row/col to update remaining elements
        for i in range(1, row_num):
            if matrix[i][0] == 0:
                matrix[i][:] = [0] * col_num
        for j in range(1, col_num):
            if matrix[0][j] == 0:
                for i in range(0, row_num):
                        matrix[i][j] = 0

        # update the first row/col
        if first_row == 0:
            matrix[0][:] = [0] * col_num
        if first_col == 0:
            for i in range(0, row_num):
                matrix[i][0] = 0
