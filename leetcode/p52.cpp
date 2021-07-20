class Solution {
public:
    vector<bool> col;
    vector<bool> diag0;
    vector<bool> diag1;
    int N;
    int res;
    void dfs(int row) {
        if (row == N) {
            res++;
            return;
        }
        for (int c=0;c<N;c++) {
            int d0 = N + row - c;
            int d1 = row + c;
            if (col[c] || diag0[d0] || diag1[d1]) continue;
            col[c] = true;
            diag0[d0] = true;
            diag1[d1] = true;
            dfs(row+1);
            col[c] = false;
            diag0[d0] = false;
            diag1[d1] = false;
        }
    }
    int totalNQueens(int n) {
        col.resize(n, false);
        diag0.resize(2*n, false);
        diag1.resize(2*n, false);
        N = n;
        res = 0;
        dfs(0);
        return res;
    }
};
