class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, left = 0, right = matrix[0].size() - 1, bottom = matrix.size() - 1;
        int N = (right + 1) * (bottom + 1);
        int i = 0, j = 0;
        while (result.size() < N) {
            for (int j = left; j <= right; ++j) { 
                result.push_back(matrix[top][j]);
                // cout << result.back() << endl;
            }
            if (result.size() >= N) {
                break;
            }
            top++;
            // cout << top << "," << right << "," << bottom << "," << left << ", after moving to right" << endl;
            for (int i = top; i <= bottom; ++i) {
                result.push_back(matrix[i][right]);
                // cout << result.back() << endl;
            }
            if (result.size() >= N) {
                break;
            }
            right--;
            // cout << top << "," << right << "," << bottom << "," << left << ", after moving to bottom" << endl;
            for (int j = right; j >= left; --j) {
                result.push_back(matrix[bottom][j]);
                // cout << result.back() << endl;
            }
            if (result.size() >= N) {
                break;
            }
            bottom--;
            // cout << top << "," << right << "," << bottom << "," << left << ", after moving to left" << endl;
            for (int i = bottom; i >= top; --i) {
                result.push_back(matrix[i][left]);
                // cout << result.back() << endl;
            }
            left++;
            // cout << top << "," << right << "," << bottom << "," << left << ", after moving to top" << endl;
        }

        return result;
    }
};