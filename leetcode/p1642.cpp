class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int tot = 0;
        for (int i=0;i<heights.size()-1;i++) {
            if (heights[i+1]<=heights[i]) continue;
            pq.push(heights[i+1]-heights[i]);
            if (pq.size()>ladders) {
                int t = pq.top();
                pq.pop();
                tot += t;
                if (tot>bricks) return i;
            }
        }
        return heights.size()-1;
    }
};
