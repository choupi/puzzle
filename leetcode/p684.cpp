// 684. Redundant Connection
// https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    vector<int> mp;
    int find(int node) {
        if (mp[node]==INT_MAX) mp[node] = node;
        int t = mp[node];
        stack<int> stk;
        while (mp[t]!=t) {
            stk.push(t);
            t = mp[t];
        }
        while (!stk.empty()) {
            mp[stk.top()] = t;
            stk.pop();
        }
        return t;
    }
    void join(int n1, int n2) {
        int t1 = find(n1);
        int t2 = find(n2);
        int t = min(t1, t2);
        mp[t1] = t;
        mp[t2] = t;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        mp.resize(1001, INT_MAX);
        for (auto e: edges) {
            int t1 = find(e[0]);
            int t2 = find(e[1]);
            if (t1==t2) return e;
            join(e[0], e[1]);
        }
        return {-1, -1};
    }
};
