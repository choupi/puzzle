class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2) return 0;
        sort(nums.begin(), nums.end());
        int m = 0;
        for (int i=1;i<nums.size();i++) {
            int t = abs(nums[i] - nums[i-1]);
            m = max(m, t);
        }
        return m;
    }
};
