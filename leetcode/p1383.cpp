// https://leetcode.com/problems/maximum-performance-of-a-team/
// 1383. Maximum Performance of a Team

class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> eng(n);
        for (int i=0;i<n;i++) {
            eng[i] = {efficiency[i], speed[i]};
        }
        sort(eng.rbegin(), eng.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ss = 0;
        long long total = INT_MIN;
        for (int i=0;i<k;i++) {
            auto [e, s] = eng[i];
            pq.push(s);
            ss += s;
            long long t = ss * e;
            //cout << ss << "*" << e << "=" << t << endl;
            total = max(total, t);
        }
        for (int i=k;i<n;i++) {
            auto [e, s] = eng[i];
            ss -= pq.top();
            pq.pop();
            ss += s;
            pq.push(s);
            long long t = ss * e;
            //cout << ss << "*" << e << "=" << t << endl;
            total = max(total, t);
        }
        return total % (int) (1e9+7);
    }
};
