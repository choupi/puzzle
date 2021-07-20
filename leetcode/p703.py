import heapq

class KthLargest:

    def __init__(self, k: int, nums: List[int]):
        self.kheap = nums[:k]
        self.k = k
        heapq.heapify(self.kheap)
        for n in nums[k:]:
            self.add(n)

    def add(self, val: int) -> int:
        if len(self.kheap) < self.k:
            heapq.heappush(self.kheap, val)
        elif val > self.kheap[0]:
            heapq.heapreplace(self.kheap, val)
        return self.kheap[0]

# Your KthLargest object will be instantiated and called as such:
# obj = KthLargest(k, nums)
# param_1 = obj.add(val)
