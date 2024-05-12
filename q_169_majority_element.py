class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        ##################################################
        # Solution 3, moore voting algo
        # candidate = nums[0]
        # vote = 1
        # for n in nums:
        #     if n == candidate:
        #         vote += 1
        #     else:
        #         vote -= 1
        #         if vote == 0:
        #             candidate = n
        #             vote = 1

        # return candidate

        ##################################################
        
        ##################################################
        # Solution 2, use sort first, time O(n log n), space O(1)
        # nums.sort()
        # n_maj = nums[len(nums)//2]
        # return n_maj
        ##################################################

        ##################################################
        # Solution 1, use dict, time O(n), space O(n)
        count = {}
        n_maj = nums[0]
        # The threshold is KNOWN from problem description
        freq_threshold = len(nums) // 2
        
        for n in nums:
            if n in count:
                count[n] += 1
                if count[n] > freq_threshold:
                    n_maj = n
                    break
            else:
                count[n] = 1
        return n_maj
        ##################################################
