#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t l = 0;
        for (auto i = s.begin(); i != s.end(); ++i ) {
            unordered_set<char> string_set = {*i};
            auto j = i+1;
            while ((string_set.find(*j) == string_set.end()) && (j != s.end()) ) {
                string_set.insert(*j);
                ++j;
            }
            l = std::max(l, string_set.size());
        }
        return l;
    }
};
