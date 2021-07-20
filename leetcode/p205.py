class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        mapping = {}
        chset = set()
        for i, ch in enumerate(s):
            if ch not in mapping:
                if t[i] in chset:
                    return False
                mapping[ch] = t[i]
                chset.add(t[i])
            elif mapping[ch] != t[i]:
                return False
        return True
