# 23. Merge k Sorted Lists
# https://leetcode.com/problems/merge-k-sorted-lists/

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    import heapq
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        hp=[]
        for i in range(len(lists)):
            if lists[i]==None: continue
            v=lists[i].val
            heapq.heappush(hp, (v, i))
            lists[i]=lists[i].next
        sorted_list=None
        cur_list=None
        while hp:
            v,i=heapq.heappop(hp)
            node=ListNode(v)
            if cur_list:
                cur_list.next=node
                cur_list=node
            else:
                sorted_list=node
                cur_list=node
            if lists[i]:
                v=lists[i].val
                heapq.heappush(hp, (v,i))
                lists[i]=lists[i].next
        return sorted_list
