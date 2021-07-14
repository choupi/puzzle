// 791. Custom Sort String
// https://leetcode.com/problems/custom-sort-string/

class Solution {
public:
    string customSortString(string order, string str) {
        vector<int> alpha(26, 0);
        unordered_set<char> st;
        for (char c: str) {
            alpha[c-'a']++;
            st.insert(c);
        }
        string res;
        for (char c: order) {
            st.erase(c);
            if (alpha[c-'a']==0) continue;
            res.append(alpha[c-'a'], c);
        }
        for (char c: st) {
            res.append(alpha[c-'a'], c);
        }
        return res;
    }
};
