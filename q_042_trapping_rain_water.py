class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        # W   = [0,1,0,2,1,0,1,3,2,1,2,1]
        # H = max(H[i-1], W[i])
        # H   = [0,1,1,2,2,2,2,3,3,3,3,3] Left -> 
        # max = 7
        #  Right -> left (), min(max(water), H), til max 
        # H   = [0,1,1,2,2,2,2,3,2,2,2,1]
        # sum(H) - sum(W)
        
        water_acc = 0
        i = 1
        max_height_left = height[0]
        while (i < len(height)):
            if (height[i] >= max_height_left):
                max_height_left = height[i]
            else:
                water_acc += max_height_left - height[i]
            # print('i=', i, ', max_height_left=', max_height_left, 'water_acc=', water_acc)
            i += 1
        # print(water_acc)
        i = len(height) - 1
        max_height_right = height[-1]
        while (height[i] < max_height_left):
            if (height[i] > max_height_right):
                max_height_right = height[i]
            water_acc -= (max_height_left - max_height_right)
            i -= 1
        # print(H)
        return water_acc