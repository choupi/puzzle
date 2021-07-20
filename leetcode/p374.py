# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        up = n+1
        low = 0
        cursor = (up+low)//2
        while True:
            r = guess(cursor)
            if r==0:
                return cursor
            elif r > 0:
                low = cursor
                cursor = (cursor+up)//2
            elif r < 0:
                up = cursor
                cursor = (low+cursor)//2
