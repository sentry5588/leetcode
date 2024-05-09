class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        /* ================================================================
         * 3rd solution */
        int i = m + n - 1;
        int i1 = m - 1;
        int i2 = n - 1;
        while (i1 >= 0 && i2 >= 0) { // both list non empty
            if (nums1[i1] >= nums2[i2]) {
                nums1[i] = nums1[i1];
                i1--;
            } else {
                nums1[i] = nums2[i2];
                i2--;
            }
            i--;
        }

        while (i2 >= 0) {
            nums1[i] = nums2[i2];
            i2--;
            i--;
        }

        /* ================================================================
         * 2nd solution
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i]; // Append nums2 to nums1
        }
        sort(nums1.begin(), nums1.end()); */
        
        /* ================================================================
         * First solution 
        int p1 = 0, p2 = 0; // Pointer to the current elements
        vector<int> nums; // TODO: how to avoid creating a new array

        for (int i = 0; i < m + n; ++i) {
            if (p1 == m)
            {
                for (int j = 0; j < m + n - i; ++j) {
                    nums.push_back(nums2[p2+j]);
                }
                break;
            } else if (p2 == n) {
                for (int j = 0; j < m + n - i; ++j) {
                    nums.push_back(nums1[p1+j]);
                }
                break;
            }
            else if (nums1[p1] <= nums2[p2]){
                nums.push_back(nums1[p1]);
                ++p1;
            } else {
                nums.push_back(nums2[p2]);
                ++p2;
            }
        }

        for (int i = 0; i < m + n; ++i) {
            nums1[i] = nums[i];
        } */
    }
};