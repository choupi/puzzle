class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        unordered_set<int> remove;
        for (int i=0;i<s.size();i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (stk.empty()) {
                    remove.insert(i);
                } else {
                    stk.pop();
                }
            }
        }
        while (!stk.empty()) {
            int i = stk.top();
            remove.insert(i);
            stk.pop();
        }
        string str;
        for (int i=0;i<s.size();i++) {
            if (remove.find(i) != remove.end()) continue;
            str.append(1, s[i]);
        }
        return str;
    }
};
