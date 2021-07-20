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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1;
        ListNode* node=head;
        int len = 0;
        while (node) {
            len++;
            if (len==k) n1=node;
            node = node->next;
        }
        int cnt = len-k;
        node = head;
        while (cnt>0) {
            node = node->next;
            cnt--;
        }
        int t = n1->val;
        n1->val = node->val;
        node->val = t;
        return head;
    }
};
