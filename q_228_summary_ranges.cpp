class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = 0, r = 0;
        vector<string> output;
        while (r < nums.size()) {

            // Condition to add to output
            if ( (r + 1 == nums.size()) || (nums[r] + 1 != nums[r+1]) ) {
                if (l == r) {
                    output.push_back(to_string(nums[l]));
                } else {
                    output.push_back(to_string(nums[l]) + "->" + to_string(nums[r]));
                }
                l = r + 1;
            } 
            r++;
        }
        return output;
    }
};