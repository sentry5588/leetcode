class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* ====================================================
         * Solution 1: two pointers  */
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int i = 0, j = v.size() - 1;
        while (i < j) {
            if (v[i].first + v[j].first > target) {
                --j;
            } else if (v[i].first + v[j].first < target) {
                ++i;
            } else {
                break;
            }
        }
        return (vector<int>){v[i].second, v[j].second};

        /* ====================================================
         * Solution 2: hash table
         * This method natually handles duplicated cases cleverly
        unordered_map<int,int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.find(target - nums[i]) != m.end()) {
                return {i, m[target - nums[i]]};
            } else {
                m.insert({nums[i], i});
            }
        }
        return {-1, -1}; */

        /* ====================================================
         * Wrong method: map can't handle duplicated elements, 
         * such as [3, 3], target = 6 

        map<int,int> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.insert({nums[i], i});
        }
        auto it1 = v.begin(), it2 = v.end();
        it2--;
        while (it1->first < it2->first) {
            if (it1->first + it2->first > target) {
                --it2;
            } else if (it1->first + it2->first < target) {
                ++it1;
            } else {
                break;
            }
        }
        return (vector<int>){it1->second, it2->second}; */

    }
};