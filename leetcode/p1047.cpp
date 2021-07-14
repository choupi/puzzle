// 1047. Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for (char ch: s) {
            if (!stk.empty() && ch == stk.top()) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        string res;
        while (!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
