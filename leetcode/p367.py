class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        p = 1
        while p*p < num:
            p *= 2
        if p*p == num:
            return True
        low = p//2
        high = p
        while low < high - 1:
            p = (low + high) // 2
            print(low, high, p)
            pp = p*p
            if pp == num:
                return True
            if pp > num:
                high = p
            else:
                low = p
        return False
