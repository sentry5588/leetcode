class Solution:
    def nearby_live(self, board: List[List[int]], i: int, j: int) -> int:
        count = 0
        for row in range(max(0,i-1), min(len(board),i+2)):
            for col in range(max(0,j-1), min(len(board[0]),j+2)):
                if (row == i) and (col == j):
                    continue
                else:
                    if board[row][col] == 1 or board[row][col] > 19:
                        count = count + 1
        return count

    def gameOfLife(self, board: List[List[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        # [[0,1,0],
        #  [0,0,1],
        #  [1,1,1],
        #  [0,0,0]]

        # [[11,21,12], # nearby count. 
        #  [13,15,23], # use [10 to 18] represent previous dead cell
        #  [21,23,22], # use [20 to 28] represent previous live cell
        #  [12,13,12]]

        # [[0,0,1],   # re-assign to 0/1
        #  [1,0,1],
        #  [0,1,1],
        #  [0,1,0]]

        # Time O(mn), space O(1)

        # nearby count
        for i in range (0, len(board)):
            for j in range(0, len(board[0])):
                # print(f"{i=}, {j=}")
                if board[i][j] == 0:
                    board[i][j] = self.nearby_live(board, i, j) + 10
                else:
                    board[i][j] = self.nearby_live(board, i, j) + 20
        # print(f"{board=}")

        # re-assign to 0/1
        for i in range (0, len(board)):
            for j in range(0, len(board[0])):
                if board[i][j] == 13 or board[i][j] == 22 or board[i][j] == 23:
                    board[i][j] = 1
                else:
                    board[i][j] = 0