class Solution {
public:
    vector<vector<bool>> pac;
    vector<vector<bool>> atl;
    int R;
    int C;
    void run(vector<vector<bool>>& tab, vector<vector<int>>& matrix, int rr, int cc) {
        queue<pair<int, int>> q;
        for (int i=0;i<C;i++) {
            tab[rr][i] = true;
            q.push({rr, i});
        }
        for (int i=0;i<R;i++) {
            tab[i][cc] = true;
            q.push({i, cc});
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            if (i+1<R && tab[i+1][j]==false && matrix[i+1][j]>=matrix[i][j]) {
                tab[i+1][j] = true;
                q.push({i+1, j});
            }
            if (j+1<C && tab[i][j+1]==false && matrix[i][j+1]>=matrix[i][j]) {
                tab[i][j+1] = true;
                q.push({i, j+1});
            }
            if (i-1>=0 && tab[i-1][j]==false && matrix[i-1][j]>=matrix[i][j]) {
                tab[i-1][j] = true;
                q.push({i-1, j});
            }
            if (j-1>=0 && tab[i][j-1]==false && matrix[i][j-1]>=matrix[i][j]) {
                tab[i][j-1] = true;
                q.push({i, j-1});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        R = matrix.size();
        vector<vector<int>> res;
        //cout << R << C << endl;
        if (R==0) return res;
        C = matrix[0].size();
        pac.resize(R, vector<bool>(C, false));
        atl.resize(R, vector<bool>(C, false));
        run(pac, matrix, 0, 0);
        run(atl, matrix, R-1, C-1);
        for (int i=0;i<R;i++) {
            for (int j=0;j<C;j++) {
                //cout << pac[i][j] << atl[i][j] << " ";
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
            //cout << endl;
        }
        return res;
    }
};
