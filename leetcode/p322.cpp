class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount+1, 0);
        sort(coins.begin(), coins.end());
        //cout << coins[0] << endl;
        for (int i=1;i<amount+1;i++) {
            int m = INT_MAX;
            for (int c: coins) {
                //cout << c << " " << amount << endl;
                if (c<=i && table[i-c]<INT_MAX) m = min(m, table[i-c]+1);
                else if (c>i) break;
            }
            //cout << i << " " <<" " << m << endl;
            table[i] = m;
        }
        if (table[amount] == INT_MAX) return -1;
        return table[amount];
    }
};
