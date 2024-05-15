class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_price = prices[0], profit = 0;
        for (auto p : prices) {
            if (p < buy_price) {
                buy_price = p;
            }
            if (p - buy_price > profit) {
                profit = p - buy_price;
            }
        }
        return profit;

        // L, H
        // S = [7,1,5,3,6,4]
        // L = [7,1,1,1,1,1] *** It turns out that this is not needed neither
        // H = [7,6,6,6,6,4] Not needed
        //H-L= [0,5,5,5,5,3] Not needed
        //S-L= [0,0,4,2,5,3]  *** It turns out that this is not needed neither

        //     [7,6,4,3,1]
        // L = [7,6,4,3,1]
        // H = [7,6,4,3,1]
        //H_L= [0,0,0,0,0]

        //     [5]
        // L = [5]
        // H = [5]
        //H-L= [0]

        // S = [8,9,2,4,1,2]
        // L = [8,8,2,2,1,1]
        //S-L= [0,1,0,2,0,1]
        
    }
};