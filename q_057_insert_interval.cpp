class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
        // intv[i][1] >= new_intv[0]; i = 0, 1, 
        // intv[j][0] <= new_intv[1]; j = 4, 3, 
        // select {min(intv[i][0], new_intv[0]), min(intv[j][1], new_intv[1])}}
        // intervals = [[1,3],[6,9]], newInterval = [2,5]
        // [[1,2]]  new: [[1,2]]
        // [[1,2]]  new: [[0,3]]
        vector<vector<int>> merged_intv;
        int i = 0, j = intervals.size() - 1;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            i++;
        }
        if (i == intervals.size()) {
            intervals.push_back(newInterval);
            return intervals;
        }
        while (j >= 0 && intervals[j][0] > newInterval[1]) {
            j--;
        }
        if (j == -1) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        if (i > j) {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }
        // cout << "i=" << i << ", j=" << j << endl;
        for (int k = 0; k < intervals.size(); ++k) {
            // cout << "i=" << i << ", j=" << j << ", k=" << k << endl;
            if (k < i || k > j) {
                merged_intv.push_back(intervals[k]);
            } else {
                merged_intv.push_back(vector<int>{min(intervals[i][0], newInterval[0]), 
                                                  max(intervals[j][1], newInterval[1])});
                k = j;
            }
        }
        return merged_intv;
    }
};