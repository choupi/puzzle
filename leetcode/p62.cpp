class Solution {
public:
    vector<vector<int>> table;
    int uniquePaths(int m, int n) {
        table.resize(m, vector<int>(n, 0));
        table[0][0] = 1;
        for (int i=1;i<n;i++) {
            table[0][i] = table[0][i-1];
        }
        for (int i=1;i<m;i++) {
            table[i][0] = table[i-1][0];
        }
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
        return table[m-1][n-1];
    }
};
