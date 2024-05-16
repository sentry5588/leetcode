class Solution {
public:
    bool canJump(vector<int>& nums) {
        /* Solution 2: From right to left */
        int i = nums.size() - 1; // The target index
        while (i > 0) {
            int j = i - 1; // The index for the viable previous step
            while (j >= 0 && j + nums[j] < i) {
                j--; // Because no viable previous step found, keep going
                if (j < 0) { // Even the first element won't work, BOOM!
                    return false;
                }
            }
            i = j; // Able to find a viable previous step
        }
        return true; // Able to move the target to the first element

        /* Solution 1: My solution from left to right
        // Essentially this is a graph problem, but it's special structure
        // allows me to solve it without using graph theory,
        // such as testing if the graph is connected or not

        // algo: if all n > 0, then ok
        //       if any n is 0, then there need a previous jump to overcome the 0
        int i = 0;
        bool r = true;
        while (i < nums.size()) {
            i += nums[i];
            if (i >= nums.size()-1) { // Reached the last element
                break;
            }
            if (nums[i] == 0) {
                int j = i - 1;
                while (j >= 0) {
                    cout << "i=" << i << ", j=" << j << endl;
                    if (nums[j] - nums[i] > i - j) { // overcome 0
                        i = j + nums[j];
                        break;
                    }
                    j--;
                }
                if (j < 0) {
                    r = false;
                    break;
                }
            }
        }
        return r; */
    }
};