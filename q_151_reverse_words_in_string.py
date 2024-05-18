class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        # ###########################################
        # Solution 2: join
        return ' '.join(reversed(s.split()))
        # ###########################################

        # ###########################################
        # Solution 1: my solution 
        # word_list = s.split()
        # r = word_list[-1]
        # i = len(word_list) - 2
        # while (i >= 0):
        #     r += " "
        #     r += word_list[i]
        #     i -= 1
        # return r
        # ###########################################
