class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> st_map;
        for (int i = 0; i < t.size(); ++i) {
            st_map[s[i]]++; // if s[i] not in the map, automatically insert it and assign 0
            st_map[t[i]]--;
        }
        for (const auto& p : st_map) {
            if (p.second != 0) {
                return false;
            }
        }
        return true;
        
    }
};