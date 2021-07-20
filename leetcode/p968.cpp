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
enum status {
    COVERED,
    NONCOVER,
    CAMERA
};
class Solution {
public:
    int tot;
    status dfs(TreeNode* node) {
        if (node == nullptr) return COVERED;
        status l = dfs(node->left);
        status r = dfs(node->right);
        if (l == NONCOVER || r == NONCOVER) {
            tot++;
            return CAMERA;
        }
        if (l == CAMERA || r == CAMERA) {
            return COVERED;
        } else return NONCOVER;
    }
    
    int minCameraCover(TreeNode* root) {
        tot = 0;
        status r = dfs(root);
        if (r == NONCOVER) tot++;
        return tot;
    }
};
