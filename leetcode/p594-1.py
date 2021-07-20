class Solution:
    def findLHS(self, nums: List[int]) -> int:
        ns = Counter(nums)
        ns_list = sorted(ns.items())
        max_len = 0
        for i in range(len(ns_list)-1):
            if ns_list[i][0]+1 == ns_list[i+1][0] and max_len < ns_list[i][1]+ns_list[i+1][1]:
                max_len = ns_list[i][1]+ns_list[i+1][1]
        return max_len
