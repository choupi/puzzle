# 1093. Statistics from a Large Sample
# https://leetcode.com/problems/statistics-from-a-large-sample/

class Solution(object):
    def find_index(self, count, index, start=0, start_sum=0):
        s=start_sum
        for i in range(start, len(count)):
            s+=count[i]
            if s>=index: return (i, s)
    
    def find_min(self, count):
        for i in range(len(count)):
            if count[i]>0: return i
            
    def find_max(self, count):
        l=len(count)
        for i in range(l):
            if count[l-i-1]>0: return l-i-1
            
    def average(self, count, cnt_sum):
        s=0.0
        for i, v in enumerate(count):
            s+=float(v)*i
        return s/cnt_sum
            
    def sampleStats(self, count):
        """
        :type count: List[int]
        :rtype: List[float]
        """
        cnt_sum=sum(count)
        avg=self.average(count, cnt_sum)
        med_index=cnt_sum/2
        if cnt_sum%2==1: 
            med, _=self.find_index(count, med_index)
        else:
            med, med_s=self.find_index(count, med_index)
            if med_s<med_index+1:
                med_t, _ = self.find_index(count, med_index+1, med+1, med_s)
                med+=med_t
                med/=2.0
        mode=count.index(max(count))
        return [self.find_min(count), self.find_max(count), avg, med, mode]
