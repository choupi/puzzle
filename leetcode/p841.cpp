class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> visit;
        visit.insert(0);
        for (int i=0;i<rooms.size();i++) {
            for (int j=0;j<rooms[i].size();j++) {
                if (rooms[i][j]==i) continue;
                visit.insert(rooms[i][j]);
            }
        }
        if (visit.size() < rooms.size()) return false;
        queue<int> q;
        q.push(0);
        visit.erase(0);
        while (!q.empty()) {
            int r = q.front();
            q.pop();
            for (int k: rooms[r]) {
                if (visit.find(k) != visit.end()) {
                    q.push(k);
                    visit.erase(k);
                }
            }
        }
        return visit.empty();
    }
};
