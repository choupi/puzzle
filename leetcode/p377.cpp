class Solution {
public:
    vector<long long> table;
    int combinationSum4(vector<int>& nums, int target) {
        table.resize(target+1, 0);
        table[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i=1;i<target+1;i++) {
            for (int j=0;j<nums.size();j++) {
                //cout << "nums" << j << "=" << nums[j] << endl;
                if (nums[j]>i) break;
                table[i] += table[i-nums[j]];
                if (table[i]>INT_MAX) {
                    table[i] = INT_MAX;
                    break;
                }
            }
            //cout << table[i] << endl;
        }
        return table[target];
    }
};
