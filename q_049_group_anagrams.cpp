class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> r;
		// Map of map isn't working, because map itself isn't hash-able
        unordered_map<string, vector<string>> groups;
        for (auto const& s : strs) {
            auto t = s;
            sort(t.begin(), t.end()); // Time O(k log k)
            groups[t].push_back(s);   // Take space than using index
        }
        for (auto& it : groups) {
            r.push_back(it.second);
        }
        return r;
    }
};