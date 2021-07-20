// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    unordered_map<int, int> mp;
    TreeNode* gen(vector<int>& preorder, vector<int>& inorder, int pst, int ped, int ist, int ied) {
        TreeNode* root = new TreeNode(preorder[pst]);
        int iit = mp[preorder[pst]];
        int d = iit - ist;
        if (d>0) root->left = gen(preorder, inorder, pst+1, pst+d, ist, iit);
        if (ied - iit > 1) root->right = gen(preorder, inorder, pst+d+1, ped, iit+1, ied);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++) {
            mp[inorder[i]] = i;
        }
        return gen(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
