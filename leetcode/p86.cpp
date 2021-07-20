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
    ListNode* partition(ListNode* head, int x) {
        ListNode* le = new ListNode();
        ListNode* gt = new ListNode();
        ListNode* t0 = head;
        ListNode* le_tail = le;
        ListNode* gt_tail = gt;
        while (t0 != nullptr) {
            if (t0->val < x) {
                le_tail->next = t0;
                le_tail = t0;
                t0 = le_tail->next;
                le_tail->next = nullptr;
            } else {
                gt_tail->next = t0;
                gt_tail = t0;
                t0 = gt_tail->next;
                gt_tail->next = nullptr;
            }
        }
        le_tail->next = gt->next;
        return le->next;
    }
};
