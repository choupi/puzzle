class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for (int i=0;i<k;i++) {
            double d = (double)points[i][0]*points[i][0] + (double)points[i][1]*points[i][1];
            pq.push({d, i});
        }
        for (int i=k;i<points.size();i++) {
            double d = (double)points[i][0]*points[i][0] + (double)points[i][1]*points[i][1];
            auto [dd, j] = pq.top();
            if (d < dd) {
                pq.pop();
                pq.push({d, i});
            }
        }
        vector<vector<int>> res;
        while (pq.size()>0) {
            auto [d, j] = pq.top();
            pq.pop();
            res.push_back(points[j]);
        }
        return res;
    }
};
