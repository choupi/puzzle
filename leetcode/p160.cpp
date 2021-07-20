/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL or headB == NULL) return NULL;
        int len_A = 1, len_B = 1;
        ListNode *tailA = headA, *tailB = headB;
        while (tailA->next != NULL) {
            tailA = tailA->next;
            len_A++;
        }
        while (tailB->next != NULL) {
            tailB = tailB->next;
            len_B++;
        }
        if (tailA != tailB) return NULL;
        tailA = headA;
        tailB = headB;
        if (len_A > len_B) {
            len_A -= len_B;
            for (int i=0;i<len_A;i++) tailA = tailA->next;
        } else {
            len_B -= len_A;
            for (int i=0;i<len_B;i++) tailB = tailB->next;
        }
        while (tailA != tailB) {
            tailA = tailA->next;
            tailB = tailB->next;
        }
        return tailA;
    }
};
