import collections

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ns = collections.Counter(nums)
        #print(ns)
        #print(ns.most_common(1))
        return ns.most_common(1)[0][0]
