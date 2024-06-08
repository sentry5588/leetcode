class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        vector<vector<int>> non_overlap_intv;
        sort(points.begin(), points.end());
        // for (auto n : points) cout << "[" << n[0] << "," << n[1] << "], ";

        int shot = points.back()[0];
        int num_of_shots = 1;
        while (points.size() > 0) {
            // cout << "shot=" << shot << ", points.back()=[" << points.back()[0] << "," << points.back()[1] << "]" << endl;
            if (shot > points.back()[1]) {
                shot = points.back()[0];
                num_of_shots++;
            } else {
                points.pop_back();
            }
        }
        return num_of_shots;
    }
};