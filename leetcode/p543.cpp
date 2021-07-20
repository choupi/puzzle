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
    pair<int, int> dfs(TreeNode* root) {
        pair<int, int> left = {0, 0};
        pair<int, int> right = {0, 0};
        if (root->left) {
            left = dfs(root->left);
        }
        if (root->right) {
            right = dfs(root->right);
        }
        int max_d = left.first > right.first ? left.first : right.first;
        max_d = left.second+right.second > max_d ? left.second+right.second : max_d;
        int max_dep = left.second > right.second ? left.second+1 : right.second+1;
        return {max_d, max_dep};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        pair<int, int> res = dfs(root);
        return res.first;
    }
};
