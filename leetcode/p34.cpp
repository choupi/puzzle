class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it0 = lower_bound(nums.begin(), nums.end(), target);
        auto it1 = upper_bound(nums.begin(), nums.end(), target);
        int i0 = -1;
        int i1 = -1;
        if (it0!=nums.end() && *it0==target) {
            i0 = distance(nums.begin(), it0);
            i1 = distance(nums.begin(), it1)-1;
        }
        return {i0, i1};
    }
};
