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
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        ListNode* n=head;
        while (n) {
            v.push_back(n->val);
            n=n->next;
        }
        int h2 = v.size()/2;
        int l = v.size();
        for (int i=0;i<h2;i++) {
            if (v[i]!=v[l-i-1]) return false;
        }
        return true;
    }
};
