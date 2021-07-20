class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> table(m+1, vector<int>(n+1, 0));
        for (string s:strs) {
            int ones=0, zeros=0;
            for (char c: s) {
                if (c=='0') zeros++;
                else ones++;
            }
            for (int i=m;i>=zeros;i--) {
                for (int j=n;j>=ones;j--) {
                    table[i][j] = max(table[i][j], table[i-zeros][j-ones]+1);
                }
            }
        }
        return table[m][n];
    }
};
