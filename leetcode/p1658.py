class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        prefix_sum = {}
        suffix_sum = {}
        ps = 0
        ss = 0
        for i in range(len(nums)):
            ps += nums[i]
            prefix_sum[ps] = i + 1
            if ps >= x:
                break
        for i in range(len(nums)):
            ss += nums[len(nums)-i-1]
            suffix_sum[ss] = i + 1
            if ss >= x:
                break
        min_op = float('inf')
        if x in prefix_sum:
            min_op = prefix_sum[x]
        if x in suffix_sum and suffix_sum[x]<min_op:
            min_op = suffix_sum[x]
        for n in prefix_sum:
            d = x - n
            if d in suffix_sum:
                if len(nums)-suffix_sum[d] > prefix_sum[n]-1 and suffix_sum[d]+prefix_sum[n]<min_op:
                    min_op = suffix_sum[d]+prefix_sum[n]
        if min_op >= float('inf'):
            return -1
        return min_op
