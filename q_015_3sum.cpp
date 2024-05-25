class Solution {
public:
    vector<int> sort3(int a, int b, int c)
    {
        if (a > b)
        {
            std::swap(a, b);
        }
        if (b > c)
        {
            std::swap(b, c);
        }
        if (a > b)
        {
            std::swap(a, b);
        }
        vector<int> r {a, b, c};
        return r;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> r;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int third = - nums[i] - nums[j];
                if (find(nums.begin() + j + 1, nums.end(), third) != nums.end()) {
                    vector<int> n3 {nums[i], nums[j], third};
                    if (find(r.begin(), r.end(), n3) == r.end()){
                        r.push_back(n3);
                    }
                }
            }
        }
        return r;
        /* =================================
         * Solution 1: brutal force exceed time limit
        vector<vector<int>> r;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int k = j + 1; k < nums.size(); ++k) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        // for (auto n : nums) cout << n << ", ";
                        auto n3 = sort3(nums[k], nums[j], nums[i]);
                        if (find(r.begin(), r.end(), n3) == r.end()) {
                            r.push_back(sort3(nums[k], nums[j], nums[i]));
                        }
                        // cout << endl; 
                        // for (auto n : nums) cout << n << ", ";
                        // cout << endl; 
                        // for (auto n : r[0]) cout << n << ", ";
                    }
                }
            }
        }
        return r; */
    }
};