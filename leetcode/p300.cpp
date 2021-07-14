// 300. Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tab;
        for (int x: nums) {
            auto it = lower_bound(tab.begin(), tab.end(), x);
            if (it==tab.end()) {
                //cout << x << " end" << endl;
                tab.push_back(x);
            } else {
                //cout << x << " " << *it << endl;
                *it = x;
            }
        }
        return tab.size();
    }
};
