// https://leetcode.com/problems/longest-consecutive-sequence/
// 128. Longest Consecutive Sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int n: nums) {
            st.insert(n);
        }
        int m = 0;
        for (int n: nums) {
            if (st.find(n-1)!=st.end()) continue;
            int c = 1;
            while (st.find(n+1)!=st.end()) {
                n++;
                c++;
            }
            m = max(m, c);
        }
        return m;
    }
};
