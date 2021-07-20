class Solution:
    def leastBricks(self, wall: List[List[int]]) -> int:
        gap = {}
        for row in wall:
            d = 0
            for i, w in enumerate(row):
                if i == len(row)-1:
                    continue
                d += w
                gap[d] = gap.get(d, 0) + 1
        #print(gap)
        if len(gap) == 0:
            return len(wall)
        return len(wall) - max(gap.values())
