class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int change = 0;
        // Algo: Essentially all possible profit can be captured
        // Therefore just sum all possible up changes
        for (int i = 1; i < prices.size(); ++i) {
            change = prices[i] - prices[i-1];
            if (change > 0) {
                profit += change;
            }
        }

        return profit;
    }
};