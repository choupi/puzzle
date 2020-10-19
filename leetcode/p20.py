# 20. Valid Parentheses
# https://leetcode.com/problems/valid-parentheses/


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack=[]
        for c in s:
            if c in '([{': stack.append(c)
            else:
                if stack: cc=stack.pop()
                else: return False
                if c==')' and cc!='(': return False
                elif c==']' and cc!='[': return False
                elif c=='}' and cc!='{': return False
        if len(stack)>0: return False
        return True
