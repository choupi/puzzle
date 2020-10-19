# 57. Insert Interval
# https://leetcode.com/problems/insert-interval/


class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        if len(intervals)==0: return [newInterval]
        res=[]
        newinter=newInterval
        for inter in intervals:
            if newinter is None or len(newinter)==0:
                res.append(inter)
            elif inter[1]<newinter[0]:
                res.append(inter)
            elif inter[0]<=newinter[0]<=inter[1] or inter[0]<=newinter[1]<=inter[1]:
                newinter[0]=min(inter[0], newinter[0])
                newinter[1]=max(inter[1], newinter[1])
            elif newinter[1]<inter[0]: 
                res.append(newinter)
                res.append(inter)
                newinter=None
        if newinter: res.append(newinter)
        return res
