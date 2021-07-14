// 778. Swim in Rising Water
// https://leetcode.com/problems/swim-in-rising-water/

typedef tuple<int, int, int> TT;
class Solution {
public:
    vector<vector<bool>> visited;
    priority_queue<TT, vector<TT>, greater<TT>> pq;
    vector<pair<int, int>> ADJ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        visited.resize(N, vector<bool>(N, false));
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        while (!pq.empty()) {
            auto [g, i, j] = pq.top();
            pq.pop();
            for (auto [ai, aj]: ADJ) {
                int ii = i+ai;
                int jj = j+aj;
                if (ii<0 || ii>=N || jj<0 || jj>=N) continue;
                if (visited[ii][jj]) continue;
                int gg = max(g, grid[ii][jj]);
                if (ii==N-1 && jj==N-1) return gg;
                pq.push({gg, ii, jj});
                visited[ii][jj] = true;
            }
        }
        return -1;
    }
};
