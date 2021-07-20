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
    vector<int> flipNodes;
    int ind;
    bool run(TreeNode* root, vector<int>& voyage) {
        //cout << root->val << endl;
        if (ind>=voyage.size() || root->val != voyage[ind]) return false;
        if (ind+1==voyage.size()) {
            if (root->left==NULL && root->right==NULL) return true;
            else return false;
        }
        TreeNode* n=root->right;
        if (root->left!=NULL) {
            //cout << root->val << " L" << endl;
            ind += 1;
            if (voyage[ind]==root->left->val) {
                //cout << root->val << " LL" << endl;
                if (!run(root->left, voyage)) return false;
            } else if (root->right==NULL || root->right->val!=voyage[ind]) return false;
            else {
                //cout << root->val <<" LR" << endl;
                flipNodes.push_back(root->val);
                n = root->left;
                if (!run(root->right, voyage)) return false;
            }
        }
        if (n!=NULL) {
            //cout << root->val << " R" << endl;
            ind += 1;
            if (!run(n, voyage)) return false;
        }
        //cout << root->val << " end" << endl;
        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        ind = 0;
        bool r = run(root, voyage);
        if (r==false) {
            flipNodes.clear();
            flipNodes.resize(1, -1);
        }
        return flipNodes;
    }
};
