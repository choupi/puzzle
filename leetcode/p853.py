class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        car_heap = []
        for i in range(len(speed)):
            t = (target - position[i]) / speed[i]
            car_heap.append((-t, -1 * position[i]))
        heapq.heapify(car_heap)
        total = 0
        pos = -1
        while car_heap:
            t, p = heapq.heappop(car_heap)
            p = -1 * p
            if p < pos:
                continue
            total += 1
            pos = p
        return total
