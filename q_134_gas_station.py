class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        # gas  = [1,2,3,4,5]
        # cost = [3,4,5,1,2]
        # 1. Select starting point that gas[i] >= cost[i]
        # 2. Need sum(cost), total gas sum(gas)
        #        if sum(cost) > sum(gas): fail for sure
        #        else: it's feasible
        # gas  = [2 4 1 3 0]
        # cost = [2 3 2 1 2]
        # g-c  = [0 1 -1 2 -2 -1 2 -1]
        # accu = [0 1 0 2   0  -1 1 0]
        # sol  = [                2 1  0 2 1 3 1 0]
        # When there is a solution:
        """
        if sum(gas) < sum(cost):
            return -1

        remaining_gas = [x1 - x2 for (x1, x2) in zip (gas, cost)]
        i = 0
        min_gas = 1e4
        start = 0

        while (i < len(gas)):
            if i > 0:
                remaining_gas[i] += remaining_gas[i-1]
            if remaining_gas[i] < min_gas:
                min_gas = remaining_gas[i]
                if min_gas < 0:
                    start = (i+1) % len(gas)

            i += 1
        
        return start
        