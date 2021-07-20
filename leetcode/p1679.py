import collections

class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        ncounter = dict(collections.Counter(nums))
        total = 0
        for n in ncounter:
            df = k - n
            if n >= k or ncounter[n] == 0:
                continue
            elif df in ncounter and ncounter[df] > 0:
                c = min(ncounter[n], ncounter[df])
                if n == df:
                    c = c//2
                total += c
                ncounter[n] -= c
                ncounter[df] -= c
        return total
