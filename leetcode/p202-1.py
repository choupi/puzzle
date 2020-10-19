

class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        past_number=set()
        past_number.add(n)
        s=n
        while True:
            s=sum([int(i)*int(i) for i in str(s)])
            if s==1: return True
            elif s in past_number: return False
            past_number.add(s)
