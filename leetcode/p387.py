class Solution:
    def firstUniqChar(self, s: str) -> int:
        if not s:
            return -1
        ns = {}
        for i, c in enumerate(s):
            if c not in ns:
                ns[c] = [0, i, c]
            ns[c][0] += 1
        cnt, ind, _ = min(ns.values())
        if cnt > 1:
            return -1
        return ind
