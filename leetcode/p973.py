class Solution:
    def distance(self, p):
        return -1 * (p[0]**2 + p[1]**2)

    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        kheap = [(self.distance(p), p) for p in points[:K]]
        heapq.heapify(kheap)
        for p in points[K:]:
            d = self.distance(p)
            if kheap[0][0] < d:
                heapq.heapreplace(kheap, (d, p))
        return [h[1] for h in kheap]
            
