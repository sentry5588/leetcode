class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        # use dict <char : char> to represent the map
        # it should map from s to t, and from t to s
        s2t = {}
        t2s = {}
        for i in range(0, len(s)):
            if s[i] not in s2t:
                s2t[s[i]] = t[i]
            elif s2t[s[i]] != t[i]:
                return False
            if t[i] not in t2s:
                t2s[t[i]] = s[i]
            elif t2s[t[i]] != s[i]:
                return False

        return True