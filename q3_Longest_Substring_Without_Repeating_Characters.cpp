https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/

/**
 * Better, still need to improve
 * 
 * Runtime: 16 ms, faster than 70.58% of C++ online submissions for Longest Substring Without Repeating Characters.
 * Memory Usage: 7.8 MB, less than 79.34% of C++ online submissions for Longest Substring Without Repeating Characters. 
 */
 
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t l = 0;
        deque<char> q;
        for (auto i = s.begin(); i != s.end(); ++i ) {
            auto r = std::find(q.begin(), q.end(), *i);
            if (r != q.end()) {
                q.erase(q.begin(), r);
                q.erase(r);
            }
            q.push_back(*i);
            l = std::max(l, q.size());
        }
        return l;
    }
};
