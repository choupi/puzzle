// 22. Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    vector<string> res;
    void dfs(string s, int st, int ed, int n) {
        if (s.size()==2*n) {
            res.push_back(s);
            return;
        }
        if (st<n) dfs(s+"(", st+1, ed, n);
        if (ed<st) dfs(s+")", st, ed+1, n);
        return;
    }
    vector<string> generateParenthesis(int n) {
        dfs("", 0, 0, n);
        return res;
    }
};
