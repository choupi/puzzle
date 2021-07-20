/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<Node*, int>> stk;
        stk.push({root, 0});
        while (stk.size()>0) {
            auto [cur, ind] = stk.top();
            stk.pop();
            if (ind==0) res.push_back(cur->val);
            if (ind<cur->children.size()) {
                stk.push({cur, ind+1});
                stk.push({cur->children[ind], 0});
            }
        }
        return res;
    }
};
