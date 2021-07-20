class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        if (nums.size()<2) return true;
        int violation = 0;
        nums.push_back(INT_MAX);
        for (int i=0;i<nums.size()-2;i++) {
            if (nums[i]>nums[i+1]) {
                if (violation>0) return false;
                if (nums[i+2]>=nums[i]) {
                    nums[i+1] = nums[i];
                } else {
                    nums[i] = nums[i+1];
                }
                violation++;
            }
        }
        for (int i=0;i<nums.size()-2;i++) {
            if (nums[i]>nums[i+1]) violation++;
        }
        return violation<2;
    }
};
