# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        r0 = 4
        r1 = 7
        while r0 == 4:
            r0 = rand7()
        while r1 > 5:
            r1 = rand7()
        if r0 > 4:
            return r1 + 5
        return r1
