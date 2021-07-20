// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// 235. Lowest Common Ancestor of a Binary Search Tree

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
    stack<TreeNode*> stk;
    stack<TreeNode*> sp;
    stack<TreeNode*> sq;
    bool dfs(TreeNode* node, TreeNode* pq, int stk_pq) {
        if (node==pq) {
            if (stk_pq==0) sp = stk;
            else sq = stk;
            return true;
        }
        bool r = false;
        if (node->left) {
            stk.push(node->left);
            r = dfs(node->left, pq, stk_pq);
            stk.pop();
            if (r) return r;
        }
        if (node->right) {
            stk.push(node->right);
            r = dfs(node->right, pq, stk_pq);
            stk.pop();
            if (r) return r;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stk.push(root);
        dfs(root, p, 0);
        dfs(root, q, 1);
        //cout << sp.size() << " " << sq.size() << endl;
        while (sp.size()>sq.size()) sp.pop();
        while (sq.size()>sp.size()) sq.pop();
        while (!sp.empty()) {
            if (sp.top() == sq.top()) return sp.top();
            sp.pop();
            sq.pop();
        }
        return nullptr;
    }
};
