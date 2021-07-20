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
    int max_dep;
    int nsum;
    void dfs(TreeNode* node, int dep) {
        if (node->left == nullptr && node->right == nullptr) {
            if (dep > max_dep) {
                max_dep = dep;
                nsum = node->val;
            } else if (dep == max_dep) {
                nsum += node->val;
            }
            return;
        }
        if (node->left != nullptr) {
            dfs(node->left, dep+1);
        }
        if (node->right != nullptr) {
            dfs(node->right, dep+1);
        }
        return;
    }
    int deepestLeavesSum(TreeNode* root) {
        max_dep = -1;
        nsum = 0;
        dfs(root, 0);
        return nsum;
    }
};
