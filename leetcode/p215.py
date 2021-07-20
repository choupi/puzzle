import heapq

class Solution:
    def heap_select(self, nums, k):
        kheap = nums[:k:]
        heapq.heapify(kheap)
        for x in nums[k+1:]:
            if x > kheap[0]:
                heapq.heapreplace(kheap, x)
        return kheap[0]

    def quick_select(self, nums, k):
        #print(k, nums)
        pivot = sorted(nums[:3])[1]
        #print(pivot)
        larges = [n for n in nums if n>pivot]
        #print(larges)
        if k<=len(larges):
            return self.findKthLargest(larges, k)
        smalls = [n for n in nums if n<=pivot]
        return self.findKthLargest(smalls, k-len(larges))

    def findKthLargest(self, nums: List[int], k: int) -> int:
        if k == 1:
            return max(nums)
        elif k == len(nums):
            return min(nums)
        elif len(nums) < 10000:
            return sorted(nums, reverse=True)[k-1]
        elif k < 10000:
            return self.heap_select(nums, k)
        else:
            return self.quick_select(nums, k)
