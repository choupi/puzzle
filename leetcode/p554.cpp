class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> table;
        for (int i=0;i<wall.size();i++) {
            int w = 0;
            for (int j=0;j<wall[i].size()-1;j++) {
                w += wall[i][j];
                table[w] += 1;
            }
        }
        int max_cnt = 0;
        for (auto it=table.begin();it!=table.end();it++) {
            if ((*it).second > max_cnt) max_cnt = (*it).second;
        }
        return wall.size() - max_cnt;
    }
};
