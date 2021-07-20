class Solution:
    def addDigits(self, num: int) -> int:
        if num < 10:
            return num
        s = sum([int(c) for c in str(num)])
        return self.addDigits(s)
