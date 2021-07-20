class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size()<3) return res;
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size()-2;i++) {
            if (i>0 && nums[i-1]==nums[i]) continue;
            int s=i+1, e=nums.size()-1;
            while (s<e) {
                int ss = nums[i]+nums[s]+nums[e];
                //cout << ss << endl;
                if (ss>0) e--;
                else if(ss<0) s++;
                else {
                    res.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    while (s<nums.size() && nums[s-1]==nums[s]) s++;
                    e--;
                    while (e>s && nums[e+1]==nums[e]) e--;
                }
            }
        }
        return res;
    }
};
