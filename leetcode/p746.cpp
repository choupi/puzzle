// https://leetcode.com/problems/min-cost-climbing-stairs/
// 746. Min Cost Climbing Stairs

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> table(n+1, 0);
        for (int i=2;i<n+1;i++) {
            int c0 = cost[i-2] + table[i-2];
            int c1 = cost[i-1] + table[i-1];
            table[i] = min(c0, c1);
        }
        return table[n];
    }
};
