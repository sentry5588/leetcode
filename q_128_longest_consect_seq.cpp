class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> num_2_len;
        int seq_max = 0;
        for (auto n : nums) {
            if (num_2_len.contains(n)) {
                continue;
            }
            if (!num_2_len.contains(n-1) && !num_2_len.contains(n+1)) {
                num_2_len[n] = 1;
            } else if (num_2_len.contains(n-1) && !num_2_len.contains(n+1)) {
                num_2_len[n] = num_2_len[n-1] + 1;
                num_2_len[n-num_2_len[n-1]] = num_2_len[n];
            } else if (!num_2_len.contains(n-1) && num_2_len.contains(n+1)) {
                num_2_len[n] = num_2_len[n+1] + 1;
                num_2_len[n+num_2_len[n+1]] = num_2_len[n];
            } else {
                num_2_len[n] = num_2_len[n-1] + 1 + num_2_len[n+1];
                num_2_len[n-num_2_len[n-1]] = num_2_len[n];
                num_2_len[n+num_2_len[n+1]] = num_2_len[n];
            }
            // for (const auto& it : num_2_len) cout << "<" << it.first << "," << it.second << "> ";
            // cout << endl;
            seq_max = max(seq_max, num_2_len[n]);
        }
        return seq_max;
    }
};