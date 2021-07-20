class Solution {
public:
    vector<vector<int>> table;
    vector<vector<bool>> visited;
    priority_queue<pair<int, pair<int, int>>> pq; 
    int size_n;
    
    void update_pos(pair<int,int> pos, vector<vector<int>>& grid) {
        int x = pos.first;
        int y = pos.second;
        visited[x][y] = true;
        int pos_v = table[x][y]+1;
        //cout << x << y << pos_v << endl;
        for (int i=-1;i<2;i++) {
            for (int j=-1;j<2;j++) {
                if (i == 0 && j == 0) continue;
                //cout << "ij" << x+i << y+j << endl;
                if (x+i >= 0 && x+i < size_n && y+j >= 0 && y+j < size_n && grid[x+i][y+j]==0 && !visited[x+i][y+j] && table[x+i][y+j]>pos_v) {
                    //cout << "udate" << x+i << y+j << endl;
                    pq.push({-pos_v, {x+i, y+j}});
                    table[x+i][y+j] = pos_v;
                }
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        size_n = grid.size();
        if (grid[0][0] == 1 or grid[size_n-1][size_n-1] == 1)
            return -1;
        if (size_n == 1) return 1;
        table.assign(size_n, vector<int>(size_n, INT_MAX));
        visited.assign(size_n, vector<bool>(size_n, false));
        //for (int i=0;i<size_n;i++) {
        //    table[i].assign(size_n, INT_MAX);
        //}
        pq.push({-1,{0,0}});
        table[0][0] = 1;
        while (!pq.empty()) {
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            if (p.second.first == size_n -1 && p.second.second == size_n -1) return table[size_n-1][size_n-1];
            if (visited[p.second.first][p.second.second]) continue;
            update_pos(p.second, grid);
        }
        cout << table[size_n-1][size_n-1];
        if (table[size_n-1][size_n-1]<INT_MAX) {
            return table[size_n-1][size_n-1];
        }
        return -1;
    }
};
