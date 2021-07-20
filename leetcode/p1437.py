class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        min_0 = float('inf')
        cnt = float('inf')
        for n in nums:
            if n == 0:
                cnt += 1
            else:
                if cnt < min_0:
                    min_0 = cnt
                cnt = 0
        return min_0 >= k
