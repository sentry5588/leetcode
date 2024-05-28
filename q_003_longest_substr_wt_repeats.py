class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        # ##########################################################
        # Solution 3: Use set, avoid two nested loops
        # Thoughts: Since this algo is O(n), it only need 1 loop
        unique_substr_set = set()
        left = 0
        right = left
        max_len = 0
        while (right < len(s)):
            if s[right] not in unique_substr_set:
                unique_substr_set.add(s[right])
                max_len = max(max_len, len(unique_substr_set))
                right = right + 1
            else:
                unique_substr_set.remove(s[left])
                left = left + 1

        return max_len

        # ##########################################################
        # Solution 2: Use dict
        # unique_substr_dict = {}
        # left = 0
        # right = left
        # max_len = 0
        # while (left < len(s)):

        #     # For the evaluation order, refer here
        #     # https://docs.python.org/3/reference/expressions.html#boolean-operations
        #     # The expression x and y first evaluates x; 
        #     # if x is false, its value is returned; 
        #     # otherwise, y is evaluated and the resulting value is returned.
        #     while (right < len(s)) and (s[right] not in unique_substr_dict):
            
        #         unique_substr_dict[s[right]] = 1
        #         right = right + 1
                
        #     max_len = max(max_len, len(unique_substr_dict))
        #     del unique_substr_dict[s[left]]
        #     left = left + 1

        # return max_len

        # ##########################################################
        # Solution 1: Use set
        # unique_substr_set = set()
        # left = 0
        # right = left
        # max_len = 0
        # while (left < len(s)):

        #     # For the evaluation order, refer here
        #     # https://docs.python.org/3/reference/expressions.html#boolean-operations
        #     # The expression x and y first evaluates x; 
        #     # if x is false, its value is returned; 
        #     # otherwise, y is evaluated and the resulting value is returned.
        #     while (right < len(s)) and (s[right] not in unique_substr_set):
            
        #         unique_substr_set.add(s[right])
        #         right = right + 1
                
        #     max_len = max(max_len, len(unique_substr_set))
        #     unique_substr_set.remove(s[left])
        #     left = left + 1

        # return max_len
        