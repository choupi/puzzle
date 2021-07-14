// 576. Out of Boundary Paths
// https://leetcode.com/problems/out-of-boundary-paths/

class Solution {
public:
    vector<vector<long long>> curr;
    vector<vector<long long>> prev;
    int MM = 1000000007;
    int _m;
    int _n;
    int total;
    void run() {
        for (int i=0;i<_m;i++) {
            for (int j=0;j<_n;j++) curr[i][j] = 0;
        }
        for (int i=0;i<_m;i++) {
            for (int j=0;j<_n;j++) {
                if (prev[i][j]==0) continue;
                if (i==0) total = (total + prev[i][j]) % MM;
                if (i==_m-1) total = (total + prev[i][j]) % MM;
                if (j==0) total = (total + prev[i][j]) % MM;
                if (j==_n-1) total = (total + prev[i][j]) % MM;
                if (i>0) curr[i-1][j] = (curr[i-1][j]+prev[i][j]) % MM;
                if (i<_m-1) curr[i+1][j] = (curr[i+1][j]+prev[i][j]) % MM;
                if (j>0) curr[i][j-1] = (curr[i][j-1]+prev[i][j]) % MM;
                if (j<_n-1) curr[i][j+1] = (curr[i][j+1]+prev[i][j]) % MM;
            }
        }
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        _m = m;
        _n = n;
        total = 0;
        curr.resize(m, vector<long long>(n, 0));
        prev.resize(m, vector<long long>(n, 0));
        prev[startRow][startColumn] = 1;
        for (int mm=0;mm<maxMove;mm++) {
            run();
            prev.swap(curr);
        }
        return total;
    }
};
