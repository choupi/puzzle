class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> mapping(10001, -1);
        vector<int> table(n, -1);
        vector<long long> presum(n, 0);
        int st = 0;
        for (int i=0;i<n;i++) {
            presum[i] = i>0?presum[i-1]+nums[i]:nums[i];
            if (mapping[nums[i]]>=st) {
                st = mapping[nums[i]]+1;
            }
            mapping[nums[i]] = i;
            table[i] = st;
        }
        long long m = presum[0];
        for (int i=1;i<n;i++) {
            long long t = table[i]>0?presum[i]-presum[table[i]-1]:presum[i];
            m = max(m, t);
        }
        return m;
    }
};
