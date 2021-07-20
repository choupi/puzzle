class Solution:
    def countPrimes(self, n: int) -> int:
        non_primes = set()
        primes = set()
        for i in range(2, n):
            if i in non_primes:
                continue
            primes.add(i)
            t = i+i
            while t < n:
                non_primes.add(t)
                t += i
        return len(primes)
