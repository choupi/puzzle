// https://leetcode.com/problems/reverse-nodes-in-k-group/
// 25. Reverse Nodes in k-Group

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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k==1) return head;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy;
        ListNode* cur = head;
        stack<ListNode*> stk;
        while (cur!=nullptr) {
            stk.push(cur);
            //cout << cur->val << endl;
            cur = cur->next;
            if (stk.size()==k) {
                while (!stk.empty()) {
                    ListNode* t = stk.top();
                    stk.pop();
                    //cout << "stk " << t->val << endl;
                    node->next = t;
                    node = t;
                }
            }
        }
        while (stk.size()>1) stk.pop();
        if (stk.empty()) node->next = nullptr;
        else node->next = stk.top();
        //cout << dummy->val << endl;
        return dummy->next;
    }
};
