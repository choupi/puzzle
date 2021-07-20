class Solution:
    def isValid(self, s: str) -> bool:
        PDICT = {')':'(', ']':'[', '}':'{'}
        stack = []
        for c in s:
            if c in ['(', '[', '{']:
                stack.append(c)
            elif c in PDICT:
                if not stack:
                    return False
                cc = stack.pop(-1)
                if cc != PDICT[c]:
                    return False
        if stack:
            return False
        return True
