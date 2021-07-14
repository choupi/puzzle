// 1004. Max Consecutive Ones III
// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0, j=0;
        int cnt0=0;
        int m=0;
        while (j<n) {
            if (nums[j]==0) {
                cnt0++;
            }
            j++;
            while (cnt0>k) {
                if (nums[i]==0) cnt0--;
                i++;
            }
            if (j-i>m) m = j-i;
        }
        return m;
    }
};
