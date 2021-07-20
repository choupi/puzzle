import itertools
class Solution:
    def update(self, n, ndict):
        nd = {}
        for x in ndict:
            nd[x+n] = nd.get(x+n, 0) + ndict[x]
            nd[x-n] = nd.get(x-n, 0) + ndict[x]
        return nd
    
    def findTargetSumWays(self, nums: List[int], S: int) -> int:
        if nums[0] == 0:
            ndict = {0: 2}
        else:
            ndict = {nums[0]: 1, -1*nums[0]: 1}
        for n in nums[1:]:
            ndict = self.update(n, ndict)
        return ndict.get(S, 0)
