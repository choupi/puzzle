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
    vector<double> lv_sum;
    vector<int> lv_cnt;
    void dfs(TreeNode* node, int l) {
        if (lv_cnt.size()<=l) {
            lv_sum.push_back(node->val);
            lv_cnt.push_back(1);
        } else {
            lv_sum[l] += node->val;
            lv_cnt[l]++;
        }
        if (node->left) dfs(node->left, l+1);
        if (node->right) dfs(node->right, l+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) return lv_sum;
        dfs(root, 0);
        for (int i=0;i<lv_sum.size();i++) {
            //cout << lv_sum[i] << " " << lv_cnt[i] << endl;
            lv_sum[i] = lv_sum[i] / lv_cnt[i];
        }
        return lv_sum;
    }
};
