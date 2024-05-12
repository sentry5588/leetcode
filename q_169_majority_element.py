class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n_maj = nums[0]
        max_freq = 1

        ##################################################
        # Solution 2, use sort first, time O(n log n), space O(1)
        nums.sort()
        print(nums) # Makesure sort correctly
        freq = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                freq += 1
            else:
                if freq > max_freq:
                    n_maj = nums[i-1]
                    max_freq = freq
                freq = 1
        if freq > max_freq:
            n_maj = nums[-1]
        ##################################################

        ##################################################
        # Solution 1, use dict, time O(n), space O(n)
        # count = {}
        # for n in nums:
        #     if n in count:
        #         count[n] += 1
        #         if count[n] > max_freq:
        #             max_freq = count[n]
        #             n_maj = n
        #     else:
        #         count[n] = 1
        ##################################################

        return n_maj