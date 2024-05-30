class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int N = 9;
        int n = 3;
        // Loop for rows and cols
        for (int i = 0; i < N; ++i) { // Row loop
            set<int> row_set; // For the i-th row
            set<int> col_set;
            for (int j = 0; j < N; ++j) { // Col loop
                // cout << "i=" << i << ", j=" << j << endl;
                if (isdigit(board[i][j])) {
                    if (row_set.contains(board[i][j])) {
                        // cout << "row " << i << " has duplicates" << "board[i][j]=" << board[i][j] << endl;
                        return false;
                    } else {
                        row_set.insert(board[i][j]);
                    }
                }
                if (isdigit(board[j][i])) {
                    if (col_set.contains(board[j][i])) {
                        // cout << "col " << i << " has duplicates" << "board[j][i]=" << board[j][i] << endl;
                        return false;
                    } else {
                        col_set.insert(board[j][i]);
                    }
                }
            }
        }
        // cout << "rows and cols are good" << endl;

        // Loop for sub-blocks
        for (int i_start = 0; i_start < N; i_start = i_start + 3) {
            for (int j_start = 0; j_start < N; j_start = j_start + 3) {
                // cout << "i_start=" << i_start << ", j_start=" << j_start << endl;
                set <int> block_set;
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        // cout << "i=" << i << ", j=" << j << endl;
                        if (isdigit(board[i_start + i][j_start + j])) {
                            if (block_set.contains(board[i_start + i][j_start + j])) {
                                // cout << "block (" << i_start + i << "," << j_start + j 
                                //         << ") has duplicates of " << board[i_start + i][j_start + j] << endl;
                                return false;
                            } else {
                                block_set.insert(board[i_start + i][j_start + j]);
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};