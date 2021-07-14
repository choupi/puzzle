// 871. Minimum Number of Refueling Stops
// https://leetcode.com/problems/minimum-number-of-refueling-stops/

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int cur = startFuel;
        int cnt = 0;
        int i = 0;
        while (cur < target) {
            while (i<stations.size() && stations[i][0]<=cur) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.size()==0) return -1;
            cur += pq.top();
            pq.pop();
            cnt++;
        }
        return cnt;
    }
};
