class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        # ##########################################################
        # Solution 2: Use two pointers
        i = 0
        j = 0
        accu = nums[0]
        min_size = len(nums) + 1
        while True:
            # print('i=', i, 'j=', j, 'accu=', accu, 'min_size=', min_size)
            if accu < target:
                j += 1
                if j == len(nums):
                    break
                accu = accu + nums[j]
            else:
                min_size = min(min_size, j - i + 1)
                accu = accu - nums[i]
                i += 1
        
        if min_size == len(nums) + 1:
            min_size = 0

        return min_size
        # ##########################################################


        # ##########################################################
        # Solution 1: Use two loops
        #           Time Limit Exceeded (TLE)
        # nums.sort(reverse=True)
        # print(nums)
        # min_size = len(nums) + 1
        
        # for i, n in enumerate(nums):
        #     j = i
        #     accu = 0
        #     found = 0
        #     while (j < len(nums)):
        #         accu = accu + nums[j]
        #         if accu >= target:
        #             found = 1
        #             if min_size > j - i + 1:
        #                 min_size = j - i + 1
        #             break
        #         j = j + 1
        #     if j == len(nums) and found == 0:
        #         break
        #     # print('accu=', accu, 'n=', n, 'i=', i, 'min_size=', min_size)
        
        # if min_size == len(nums) + 1:
        #     min_size = 0

        # return min_size
        # ##########################################################
        