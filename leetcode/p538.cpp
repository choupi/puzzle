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
    int dfs(TreeNode* node, int current_sum) {
        if (node->right != NULL) {
            current_sum = dfs(node->right, current_sum);
        }
        current_sum += node->val;
        node->val = current_sum;
        if (node->left != NULL) {
            current_sum = dfs(node->left, current_sum);
        }
        return current_sum;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        dfs(root, 0);
        return root;
    }
};
