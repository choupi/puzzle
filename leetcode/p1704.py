class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        ALPHAS = set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'])
        sl = len(s)
        ta = sum([1 for c in s[:sl//2] if c in ALPHAS])
        tb = sum([1 for c in s[sl//2:] if c in ALPHAS])
        return ta == tb
