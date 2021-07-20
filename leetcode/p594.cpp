class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> counter;
        int max_len = 0;
        for (int i=0;i<nums.size();i++) {
            counter[nums[i]]++;
        }
        for (auto it: counter) {
            int t = it.first;
            if (counter.find(t+1) != counter.end() && counter[t]+counter[t+1]>max_len) {
                max_len = counter[t]+counter[t+1];
            }
        }
        return max_len;
    }
};
