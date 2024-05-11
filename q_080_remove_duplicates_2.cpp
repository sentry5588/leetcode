class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 2, j = 1;

        // Mistake 2: Forgot edge cases
        if (nums.size() <= 2) {
            return nums.size();
        }

        while (i < nums.size()) {
            if (nums[i] == nums[j-1]) { // Mistake 1, used nums[i-2]
                i++;
            } else {
                j++;
                nums[j] = nums[i];
                i++;
            }
        }
        return j+1;
    }
};