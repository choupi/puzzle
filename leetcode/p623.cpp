/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* node, int depth, int v, int d) {
        if (depth == d) {
            TreeNode* left = new TreeNode(v, node->left, NULL);
            node->left = left;
            TreeNode* right = new TreeNode(v, NULL, node->right);
            node->right = right;
            return;
        }
        if (node->left) dfs(node->left, depth+1, v, d);
        if (node->right) dfs(node->right, depth+1, v, d);
    }
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d==1) {
            TreeNode* t = new TreeNode(v, root, NULL);
            return t;
        }
        dfs(root, 2, v, d);
        return root;
    }
};
