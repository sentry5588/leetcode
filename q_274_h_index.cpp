class Solution {
public:
    int hIndex(vector<int>& citations) {
        /* Solution 2: Learned from gpt */
        int n = citations.size();
        vector<int> pub_per_count(n + 1, 0);
        for (auto c : citations) {
            if (c >= n) {
                pub_per_count[n]++;
            } else {
                pub_per_count[c]++;
            }
        }

        int total_papers = 0;
        for (int i = n; i >= 0; --i) {
            total_papers += pub_per_count[i];
            if (total_papers >= i) {
                return i;
            }
        }
        return 0;

        /* Solution 1: Time O(n log n), not very good
        sort(citations.begin(), citations.end(), std::greater<>());
        // for (auto i : citations) cout << i << ",";
        int h = 0;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] > i) {
                ++h;
            } else {
                break;
            }
        }
        
        return h; */
    }
};