class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> table(prices.size(), vector<int>(2));
        table[0][1] = -prices[0];
        for (int i=1;i<prices.size();i++) {
            table[i][0] = max(table[i-1][0], table[i-1][1]+prices[i]-fee);
            table[i][1] = max(table[i-1][0]-prices[i], table[i-1][1]);
        }
        return table[prices.size()-1][0];
    }
};
