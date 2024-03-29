class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));
        if (obstacleGrid[0][0]!=1) table[0][0] = 1;
        for (int i=1;i<n;i++) {
            if (obstacleGrid[0][i]!=1) table[0][i] = table[0][i-1];
        }
        for (int i=1;i<m;i++) {
            if (obstacleGrid[i][0]!=1) table[i][0] = table[i-1][0];
        }
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++) {
                if (obstacleGrid[i][j]!=1) table[i][j] = table[i-1][j] + table[i][j-1];
            }
        }
        return table[m-1][n-1];
    }
};
