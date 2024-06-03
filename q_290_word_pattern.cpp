class Solution {
public:
    // This method uses lots of memory
    vector<string> split_string(string s) {
        istringstream iss(s);
        string word;
        vector<string> words;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }

    bool wordPattern(string pattern, string s) {
        auto words = split_string(s);
        if (pattern.size() != words.size()) {
            return false;
        }

        // Learn: use unordered_map rather than map
        int k = 0;
        unordered_map<char, string> pattern2words;
        unordered_map<string, char> words2pattern;
        for (int i = 0; i < pattern.size(); ++i) {
            string word = words[i];
            if (pattern2words.contains(pattern[i])) {
                 if (pattern2words[pattern[i]] != word) {
                    return false;
                 }
            } else {
                pattern2words[pattern[i]] = word;
            }
            if (words2pattern.contains(word)) {
                 if (words2pattern[word] != pattern[i]) {
                    return false;
                 }
            } else {
                words2pattern[word] = pattern[i];
            }
        }
        return true;
    }
};