class Solution(object):

    # ############################################################
    # Solution 2: Use a counter rather than dict <--> dict based include
    #             Because dict <--> dict itself is O(n) time

    def add_to_dict(self, window_dict, c):
        window_dict[c] = window_dict.get(c, 0) + 1
            
    def del_from_dict(self, window_dict, c):
        window_dict[c] = window_dict[c] - 1
        if window_dict[c] == 0:
            del window_dict[c]
            
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        if len(s) < len(t):
            return ""

        t_dict = {}
        for c in t:
            if c in t_dict:
                t_dict[c] = t_dict[c] + 1
            else:
                t_dict[c] = 1

        left = 0
        right = left
        window_dict = {}
        count = 0
        min_len = len(s) + 2
        min_len_left = 0
        min_len_right = 0

        while (left < len(s)):
            if (count < len(t)) and (right < len(s)):
                self.add_to_dict(window_dict, s[right])
                if (s[right] in t) and (window_dict[s[right]] <= t_dict[s[right]]):
                    count = count + 1
                right = right + 1
            else:
                if min_len > right - left + 1 and count == len(t): # record the best substring so far
                    min_len_left = left
                    min_len_right = right
                    min_len = right - left + 1
                if (s[left] in t) and (window_dict[s[left]] <= t_dict[s[left]]):
                    count = count - 1
                self.del_from_dict(window_dict, s[left])
                left = left + 1
        return s[min_len_left:min_len_right]


    # ############################################################
    # Solution 1: dict <--> dict based compare is in-efficient
    #             Because dict <--> dict itself is O(n) time
    # def window_contains_str(self, window_dict, t_dict):
    #     for k in t_dict:
    #         if k not in window_dict:
    #             return False
    #         elif window_dict[k] < t_dict[k]:
    #             return False
        
    #     return True

    # def minWindow(self, s, t):
    #     """
    #     :type s: str
    #     :type t: str
    #     :rtype: str
    #     """
    #     t_dict = {}
    #     for c in t:
    #         if c in t_dict:
    #             t_dict[c] = t_dict[c] + 1
    #         else:
    #             t_dict[c] = 1
    #     print(t_dict)

    #     left = 0
    #     right = left
    #     window_dict = {}
    #     min_len = len(s) + 2
    #     min_len_left = 0
    #     min_len_right = 0

    #     while (left < len(s)):
    #         if (not self.window_contains_str(window_dict, t_dict)) and (right < len(s)):
    #             if s[right] in window_dict:
    #                 window_dict[s[right]] = window_dict[s[right]] + 1
    #             else:
    #                 window_dict[s[right]] = 1
    #             right = right + 1
    #         else:
    #             if min_len > right - left + 1 and self.window_contains_str(window_dict, t_dict):
    #                 min_len_left = left
    #                 min_len_right = right
    #                 min_len = right - left + 1
    #             if window_dict[s[left]] > 1:
    #                 window_dict[s[left]] = window_dict[s[left]] - 1
    #             else:
    #                 del window_dict[s[left]]
    #             left = left + 1
    #     return s[min_len_left:min_len_right]