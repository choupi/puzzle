class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        for (int i=0;i<S.size();i++) {
            if (S[i]=='(') stk.push(-1);
            else if (S[i]==')') {
                int t = 0;
                while (stk.top() != -1) {
                    t += stk.top();
                    stk.pop();
                }
                stk.pop();
                stk.push(t>0?2*t:1);
            }
        }
        int r = 0;
        while (!stk.empty()) {
            r += stk.top();
            stk.pop();
        }
        return r;
    }
};
