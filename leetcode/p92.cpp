// 92. Reverse Linked List II
// https://leetcode.com/problems/reverse-linked-list-ii/

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        stack<ListNode*> stk;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* node = dummy;
        ListNode* prev = dummy;
        for (int i=0;i<left;i++) {
            prev = node;
            node = node->next;
        }
        for (int i=left;i<right;i++) {
            stk.push(node);
            node = node->next;
        }
        ListNode* nxt = node->next;
        prev->next = node;
        while (!stk.empty()) {
            node->next = stk.top();
            stk.pop();
            node = node->next;
        }
        node->next = nxt;
        return dummy->next;
    }
};
