class Solution {
public:
    vector<vector<int>> table;
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size()==1) return 1;
        else if (nums.size()==2 && nums[0]!=nums[1]) return 2;
        table.resize(nums.size(), vector<int>(2, 1));
        for (int i=1;i<nums.size();i++) {
            for (int j=i-1;j>=0;j--) {
                if (nums[i]>nums[j]) {
                    table[i][1] = table[j][0]+1>table[i][1]?table[j][0]+1:table[i][1];
                } else if (nums[i]<nums[j]) {
                    table[i][0] = table[j][1]+1>table[i][0]?table[j][1]+1:table[i][0];
                }
            }
        }
        return max(table[nums.size()-1][0], table[nums.size()-1][1]);
    }
};
