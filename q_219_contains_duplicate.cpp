class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = 0, r = 0;
        unordered_set<int> seen;
        while (r < nums.size()) {
            if (r - l <= k) {
                if (seen.contains(nums[r])) {
                    return true;
                } 
                seen.insert(nums[r]);
                r++;
            } else {
                seen.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};