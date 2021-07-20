class Solution:
    def hammingWeight(self, n: int) -> int:
        print(n)
        return sum([int(b) for b in bin(n)[2:]])
