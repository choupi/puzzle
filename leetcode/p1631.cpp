class Solution {
public:
    priority_queue<pair<int, pair<int, int>>> pq;
    void push(vector<vector<int>>& heights, int x, int y, int h, int max_df) {
        int df = abs(h - heights[x][y]);
        max_df = max(max_df, df);
        //cout << x << y << df << max_df << endl;
        pq.push({-1*(max_df), {x, y}});
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size(), col=heights[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        pq.push({0, {row-1, col-1}});
        while (!pq.empty()) {
            auto [v, p] = pq.top();
            pq.pop();
            //cout << p.first << p.second << v << endl;
            if (visited[p.first][p.second]) continue;
            if (p.first == 0 && p.second == 0) return -v;
            int h = heights[p.first][p.second];
            visited[p.first][p.second] = true;
            if (p.first+1<row) push(heights, p.first+1, p.second, h, -v);
            if (p.second+1<col) push(heights, p.first, p.second+1, h, -v);
            if (p.first-1>=0) push(heights, p.first-1, p.second, h, -v);
            if (p.second-1>=0) push(heights, p.first, p.second-1, h, -v);
        }
        return -1;
    }
};
