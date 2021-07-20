/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> nums;
    TreeNode* convert(int st, int ed) {
        TreeNode* node=nullptr;
        if (ed-st<1) {
            return node;
        }
        int mid = (st+ed)/2;
        node = new TreeNode(nums[mid]);
        node->left = convert(st, mid);
        node->right = convert(mid+1, ed);
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* tnode = head;
        while (tnode!=nullptr) {
            nums.push_back(tnode->val);
            tnode = tnode->next;
        }
        TreeNode* root = convert(0, nums.size());
        return root;
    }
};
