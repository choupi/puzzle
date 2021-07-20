class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        long long t1, t2;
        for (string t: tokens) {
            if (t.size()>1 || ('0'<=t[0] && t[0]<='9')) {
                stk.push(stoi(t));
                continue;
            }
            t2 = stk.top(); stk.pop();
            t1 = stk.top(); stk.pop();
            if (t == "+") {
                t2 = t1 + t2;
            } else if (t == "-") {
                t2 = t1 - t2;
            } else if (t == "*") {
                t2 = t1 * t2;
            } else if (t == "/") {
                t2 = t1 / t2;
            }
            stk.push(t2);
        }
        return stk.top();
    }
};
