// problem source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// discussion reference: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/solution/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prices_size = prices.size();
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i < prices_size; i++) {
            if (prices[i] < min_price)
                min_price = prices[i];
            else if (prices[i] - min_price > max_profit)
                max_profit = prices[i] - min_price;
        }
        return max_profit;

        // Time Limit Exceeded
        // int prices_size = prices.size();
        // int max_profit = 0;
        // for (int i = 0; i < prices_size - 1; i++) {
        //     for (int j = i + 1; j < prices_size; j++) {
        //         int comp = prices[j] - prices[i];
        //         if (comp > max_profit)
        //             max_profit = prices[j] - prices[i];
        //     }
        // }
        // return max_profit;
    }
};
