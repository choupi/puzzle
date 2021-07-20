class Solution {
public:
    vector<int> disjoint;
    int m;
    int n;
    void init() {
        disjoint.resize(m*n);
        int t = 0;
        for (int t=0;t<m*n;t++) {
            disjoint[t] = t;
        }
    }
    int find(int t) {
        stack<int> stk;
        int i = t;
        while (disjoint[i] != i) {
            stk.push(i);
            i = disjoint[i];
        }
        while (!stk.empty()) {
            disjoint[stk.top()] = i;
            stk.pop();
        }
        return i;
    }
    int join(int t0, int t1) {
        int i0 = find(t0);
        int i1 = find(t1);
        int i = min(i0, i1);
        disjoint[i0] = i;
        disjoint[i1] = i;
        return i;
    }
    int convert(int i, int j) {
        return i*n + j;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        init();
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 0) continue;
                if (i>0 && grid[i-1][j] == 1) join(convert(i, j), convert(i-1, j));
                if (j>0 && grid[i][j-1] == 1) join(convert(i, j), convert(i, j-1));
            }
        }
        vector<int> count(m*n, 0);
        int mx = 0;
        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j] == 0) continue;
                int t = find(convert(i, j));
                count[t]++;
                if (count[t]>mx) mx = count[t];
                //cout << i << " " << j << " " << t << " " << count[t] << endl;
            }
        }
        return mx;
    }
};
