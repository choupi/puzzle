// 236. Lowest Common Ancestor of a Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(stack<TreeNode*>& stk, TreeNode* node, TreeNode* p) {
        stk.push(node);
        if (node==p) return true;
        if (node->left && dfs(stk, node->left, p)) return true;
        if (node->right && dfs(stk, node->right, p)) return true;
        stk.pop();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pv;
        stack<TreeNode*> qv;
        dfs(pv, root, p);
        dfs(qv, root, q);
        while (pv.size()>qv.size()) {
            pv.pop();
        }
        while (qv.size()>pv.size()) {
            qv.pop();
        }
        while (!pv.empty()) {
            if (pv.top()==qv.top()) return pv.top();
            pv.pop();
            qv.pop();
        }
        return root;
    }
};
