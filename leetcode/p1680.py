class Solution:
    def concatenatedBinary(self, n: int) -> int:
        k = 10**9 + 7
        mod_k = 1
        total = 0
        for i in range(n, 0, -1):
            t = mod_k * i
            total += mod_k * i
            if total > k:
                total -= k
            #print(t, mod_k)
            mod_k = (mod_k * 2**(len(bin(i))-2)) % k
        return total % k
