class Solution(object):
    def checkConcat(self, m_origin, m):
        """
        :type m_origin: map[str, int]
        :type m: map[str, int]
        :rtype: bool
        """
        match = True
        for w in m_origin:
            if w in m:
                if m[w] != m_origin[w]:
                    match = False
            else:
                match = False
        return match

    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        m_origin = {}
        for w in words:
            if w in m_origin:
                m_origin[w] = m_origin[w] + 1
            else:
                m_origin[w] = 1

        N = len(words[0])
        W = len(words)
        NW = N * W
        k = 0
        result = []
        while (k < N):
            i = k
            j = i
            m = {}
            while (i <= len(s) - NW):
                while (j <= i + N * (W-1)):
                    if s[j:j+N] in m:
                        m[s[j:j+N]] = m[s[j:j+N]] + 1
                    else:
                        m[s[j:j+N]] = 1
                    j = j + N
                
                if self.checkConcat(m_origin, m):
                    result.append(i)
                if m[s[i:i+N]] > 1:
                    m[s[i:i+N]] = m[s[i:i+N]] - 1
                else:
                    del m[s[i:i+N]]

                i = i + N
            k = k + 1

        return result