class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> iset;
        vector<int> res;
        for (int i=0;i<nums.size();i++) {
            if (iset.find(nums[i]) != iset.end())
                res.push_back(nums[i]);
            iset.insert(nums[i]);
        }
        for (int i=1;i<nums.size()+1;i++) {
            if (iset.find(i) == iset.end()) {
                res.push_back(i);
                return res;
            }
        }
        return res;
    }
};
