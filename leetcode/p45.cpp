class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> table(n, 0);
        table[n-1] = 0;
        for (int i=n-2;i>=0;i--) {
            int m = INT_MAX-1;
            for (int j=i+1;j<i+nums[i]+1 && j<n;j++) {
                if (table[j]<m) m = table[j];
            }
            table[i] = m+1;
        }
        return table[0];
    }
};
