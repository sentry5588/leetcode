class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        /* Solution from batoulboutarf555 - smart */
        int i = 0;
        for (int n : nums) {
            if (n != val) {
                nums[i++] = n;
            }
        }
        return i;
        
        /* My solution - swap based, 2 pointer 
        int i1 = 0, i2 = nums.size() - 1;
        while (1) { // break based on condition
            while (i1 < nums.size() && nums[i1] != val) {
                i1++;
            }
            while (i2 >= 0 && nums[i2] == val) {
                i2--;
            }
            if (i1 < i2) { // swap
                nums[i1] = nums[i2];
                nums[i2] = val;
            } else {
                break;
            }
        }
    
        return i1;*/
    }
};