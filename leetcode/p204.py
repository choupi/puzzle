class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = False
        primes[1] = False
        for i in range(2, int(n**0.5+1)):
            if not primes[i]:
                continue
            t = i+i
            while t < n:
                primes[t] = False
                t += i
        return sum(primes)
