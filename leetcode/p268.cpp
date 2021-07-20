class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i=0;i<nums.size();i++) {
            int t = nums[i];
            while (t!=0 && nums[t-1]!=t) {
                int tt = nums[t-1];
                nums[t-1] = t;
                t = tt;
            }
        }
        for (int i=0;i<nums.size();i++) {
            if (nums[i]!=i+1) return i+1;
        }
        return 0;
    }
};
