class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> non_overlap_intv;
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

        int l = 0, r = 0;
        int current_max = intervals[l][1];
        while (r < intervals.size()) {
            current_max = max(current_max, intervals[r][1]);
            if (r + 1 == intervals.size() || intervals[r + 1][0] > current_max) {
                non_overlap_intv.push_back( (vector<int>) {intervals[l][0], current_max});
                l = r + 1;
            }
            r++;
        }
        return non_overlap_intv;
    }
};