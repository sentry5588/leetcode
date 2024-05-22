class Solution {
public:
    bool isPalindrome(string s) {
        // "A": good
        // "Aa": good
        int l = 0, r = s.size() - 1;
        while (l < r) {
			// Functions: isalpha, isdigit, isalnum, tolower, to upper
            while (l < s.size() && !isalnum(s[l])) {
                ++l;
            }
            while (r >= 0 && !isalnum(s[r])) {
                --r;
            }
            if (l < s.size() && r >= 0 && tolower(s[l]) != tolower(s[r])) {
                return 0;
            } else {
                ++l;
                --r;
            }
        }
        return 1;
    }
};