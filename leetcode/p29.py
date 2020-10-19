# 29. Divide Two Integers
# https://leetcode.com/problems/divide-two-integers/


class Solution(object):
    def mdivide(self, dividend, divisor):
        q=0
        res=dividend
        while res >= divisor:
            res-=divisor
            q+=1
        return q, res
    
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if (dividend>=0 and divisor>0) or (dividend<0 and divisor<0): sign=''
        else: sign='-'
        if dividend<0: dividend=0-dividend
        if divisor<0: divisor=0-divisor
        dividend_str=str(dividend)
        divisor_len=len(str(divisor))
        d=''
        quotient_list=[]
        for i in range(0, len(dividend_str)):
            d=str(d)+dividend_str[i]
            #print d
            q, d=self.mdivide(int(d), divisor)
            #print q, d
            quotient_list.append(str(q))
        #print quotient
        quotient=int(sign+''.join(quotient_list))
        if quotient<0: return max(-2147483648, quotient)
        else: return min(2147483647, quotient)
