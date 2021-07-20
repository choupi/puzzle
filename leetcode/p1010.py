class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        mod_list = [0] * 60
        for t in time:
            mod_list[t%60] += 1
        s = 0
        s += mod_list[0]*(mod_list[0]-1)//2
        s += mod_list[30]*(mod_list[30]-1)//2
        for i in range(1, 30):
            s += mod_list[i] * mod_list[60 - i]
        return s
