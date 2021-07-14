// 629. K Inverse Pairs Array
// https://leetcode.com/problems/k-inverse-pairs-array/

class Solution {
public:
    int M = 1000000007;
    int kInversePairs(int n, int k) {
        vector<vector<long long>> table(n+1, vector<long long>(k+1, 0));
        for (int i=0;i<n+1;i++) table[i][0] = 1;
        for (int i=1;i<n+1;i++) {
            for (int j=1;j<k+1;j++) {
                table[i][j] = table[i-1][j] + table[i][j-1];
                if (j>=i) table[i][j] = table[i][j] - table[i-1][j-i] + M;
                table[i][j] = table[i][j] % M;
            }
        }
        return table[n][k];
    }
};
