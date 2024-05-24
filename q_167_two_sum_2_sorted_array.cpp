class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1, s = 0;
        do {
            s = numbers[i] + numbers[j];
            if (s > target) {
                --j;
            } else if (s < target) {
                ++i;
            }
        } while (s != target);  // No need to test i >= j, 
                                //because solution guaranteed
        vector<int> result = {i+1,j+1};
        return result;
    }
};