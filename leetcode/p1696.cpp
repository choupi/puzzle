// https://leetcode.com/problems/jump-game-vi/
// 1696. Jump Game VI

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        pq.emplace(nums[0], 0);
        for (int i=1;i<n;i++) {
            auto [m, j] = pq.top();
            while (i-j>k) {
                pq.pop();
                tie(m, j) = pq.top();
            }
            //cout << i << " " << j << " " << i-j << " " << m+nums[i] << endl;
            if (i==n-1) return m+nums[i];
            pq.emplace(m+nums[i], i);
        }
        return 0;
    }
};
