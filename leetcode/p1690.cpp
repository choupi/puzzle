class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vector<int> dpCurr(n, 0);
        vector<int> dpLast(n, 0);
        for (int i=n-2; i>=0; i--) {
            int total = stones[i];
            dpCurr.swap(dpLast);
            for (int j=i+1;j<n;j++) {
                total += stones[j];
                dpCurr[j] = max(total - stones[i] - dpLast[j], total - stones[j] - dpCurr[j-1]);
            }
        }
        return dpCurr[n-1];
    }
};
