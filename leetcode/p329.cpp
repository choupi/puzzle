class Solution {
public:
    priority_queue<tuple<int, int, int, int>> pq;
    vector<vector<int>> table;
    int m;
    int n;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        table.resize(m, vector<int>(n, 1));
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                pq.push({-matrix[i][j], table[i][j], i, j});
            }
        }
        int max_len = 0;
        while (!pq.empty()) {
            auto [v, l, i, j] = pq.top();
            pq.pop();
            if (l<table[i][j]) continue;
            v = matrix[i][j];
            //l = table[i][j];
            if (i>0 && matrix[i-1][j]>v && table[i-1][j]<l+1) {
                table[i-1][j] = l+1;
                pq.push({-matrix[i-1][j], l+1, i-1, j});
            }
            if (j>0 && matrix[i][j-1]>v && table[i][j-1]<l+1) {
                table[i][j-1] = l+1;
                pq.push({-matrix[i][j-1], l+1, i, j-1});
            }
            if (i+1<m && matrix[i+1][j]>v && table[i+1][j]<l+1) {
                table[i+1][j] = l+1;
                pq.push({-matrix[i+1][j], l+1, i+1, j});
            }
            if (j+1<n && matrix[i][j+1]>v && table[i][j+1]<l+1) {
                table[i][j+1] = l+1;
                pq.push({-matrix[i][j+1], l+1, i, j+1});
            }
            if (l>max_len) max_len = l;
        }
        return max_len;
    }
};
