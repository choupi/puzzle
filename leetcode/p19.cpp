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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* n1=dummy;
        ListNode* n2=dummy;
        for (int i=0;i<n;i++) {
            n1 = n1->next;
        }
        while (n1->next!=nullptr) {
            n1 = n1->next;
            n2 = n2->next;
        }
        n2->next = n2->next->next;
        return dummy->next;
    }
};
