class Solution:
    def findComplement(self, num: int) -> int:
        bn = bin(num)[2:]
        bb = ''.join(['1' if b=='0' else '0' for b in bn])
        return int(bb, 2)
