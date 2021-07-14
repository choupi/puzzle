// 795. Number of Subarrays with Bounded Maximum
// https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

class Solution {
public:
    long long count(vector<int>& nums, int th) {
        long long cur = 0;
        long long total = 0;
        for (int t: nums) {
            if (t<=th) cur++;
            else cur = 0;
            total += cur;
        }
        return total;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long cnt_l = count(nums, left-1);
        long long cnt_r = count(nums, right);
        return cnt_r - cnt_l;
    }
};
