class Solution {
public:
    vector<bool> col;
    vector<int> row;
    vector<vector<string>> res;
    void search(int r, int n) {
        if (r==n) {
            string s = string(n, '.');
            vector<string> t(n, s);
            for (int i=0;i<n;i++) {
                t[i][row[i]] = 'Q';
            }
            res.push_back(t);
            return;
        }
        for (int i=0;i<n;i++) {
            if (col[i]) continue;
            bool flag = false;
            for (int j=1;r-j>=0;j++) {
                if (row[r-j]==i-j || row[r-j]==i+j) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            col[i] = true;
            row[r] = i;
            search(r+1, n);
            col[i] = false;
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        col.resize(n, false);
        row.resize(n, -1);
        search(0, n);
        return res;
    }
};
