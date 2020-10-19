# 155. Min Stack
# https://leetcode.com/problems/min-stack/

class MinStack(object):
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.min_a=[]
        self.stk_a=[]

    def push(self, x):
        """
        :type x: int
        :rtype: nothing
        """
        if not self.stk_a or self.min_a[-1]>x:
            self.min_a.append(x)
        else: self.min_a.append(self.min_a[-1])
        self.stk_a.append(x)

    def pop(self):
        """
        :rtype: nothing
        """
        del self.min_a[-1]
        del self.stk_a[-1]

    def top(self):
        """
        :rtype: int
        """
        return self.stk_a[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_a[-1]
