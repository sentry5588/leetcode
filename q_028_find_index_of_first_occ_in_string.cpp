class Solution {
public:
    int strStr(string haystack, string needle) {
        /* Solution 2: Learn - Use C++ style */
        for (int i = 0; i + needle.size() <= haystack.size(); ++i) {
            // Alert: don't use i <= haystack.size() - needle.size()
            // Because str.size() is size_t, is unsigned
            // size_t - size_t will underflow
            if (haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;

        /* Solution 1: my solution, C style
        // Test case: "sadbutsad", needle = "sad"
        // Test case: "ab", "b"
        // Solved within 10 min
        int i = 0;
        while (i < haystack.size()) {
            if (haystack[i] != needle[0]) {
                i++;
                continue;
            }
            int j = 0;
            while (j < needle.size() && haystack[i+j] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i;
            } else {
                i++;
            }
        }

        return -1; */
    }
};