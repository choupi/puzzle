class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> table;
        table.push_back(vector<int>(1, triangle[0][0]));
        for (int i=1;i<m;i++) {
            table.push_back(vector<int>(i+1));
            table[i][0] = table[i-1][0] + triangle[i][0];
            table[i][i] = table[i-1][i-1] + triangle[i][i];
            for (int j=1;j<i;j++) {
                table[i][j] = min(table[i-1][j-1], table[i-1][j]) + triangle[i][j];
            }
        }
        int res = INT_MAX;
        for (int j=0;j<m;j++) {
            if (table[m-1][j] < res) res = table[m-1][j];
        }
        return res;
    }
};
