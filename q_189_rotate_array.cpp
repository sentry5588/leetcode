class Solution {
public:
    int get_gcf(int a, int b) {
        do { // Not divide fully
            if (a < b) {
                int tmp = b;
                b = a;
                a = tmp;
            }
            a = a % b;
        } while (a);
        return b; 
    }
    void rotate(vector<int>& nums, int k) {
        // std::cout << get_gcf(15, 30) << std::endl; // Confirm gcf is correct
        k = k % nums.size();
        if (k > 0) {
            int tmp, rounds = get_gcf(nums.size(), k);
            int num_per_round = nums.size() / rounds;
            // std::cout<<"rounds="<<rounds<<", num_per_round="<<num_per_round<<std::endl;
            for (int i = 0; i < rounds; ++i) {
                int init = nums[(i - k + nums.size()) % nums.size()];
                // std::cout << "(i-k)%nums.size() = " << (i - k) << std::endl;
                // std::cout << "init=" << init << std::endl;
                for (int j = num_per_round - 1; j > 0; --j) {
                    int current = (i + j * k) % nums.size();
                    nums[current] = nums[(current - k + nums.size()) % nums.size()];
                }
                nums[i] = init; // The last value
            }
        }
    }
};