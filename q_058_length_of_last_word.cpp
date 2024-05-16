class Solution {
public:
    int lengthOfLastWord(string s) {
        // First try works, oh yeah
        int last = s.size() - 1;
        while (s[last] == ' ') {
            last--;
        }
        int start = last - 1;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }
        return last - start;
    }
};