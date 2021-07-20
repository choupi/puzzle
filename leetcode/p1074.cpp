class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<long long>> table(m, vector<long long>(n+1, 0));
        for (int i=0;i<m;i++) {
            table[i][0] = 0;
            for (int j=0;j<n;j++) {
                table[i][j+1] = table[i][j] + matrix[i][j];
            }
        }
        int res = 0;
        for (int j0=0;j0<n;j0++) {
            for (int j1=j0+1;j1<n+1;j1++) {
                long long cur = 0;
                unordered_map<long long, int> mp;
                mp[0] = 1;
                for (int i=0;i<m;i++) {
                    cur += table[i][j1] - table[i][j0];
                    res += mp[cur-target];
                    mp[cur] += 1;
                }
            }
        }
        return res;
    }
};
