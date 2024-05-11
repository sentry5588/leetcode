class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for (auto n : nums) {
            if (n != nums[j]) {
                ++j;
                nums[j] = n;
            }
        }
        return j + 1;
    }
};