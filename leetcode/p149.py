# 149. Max Points on a Line
# https://leetcode.com/problems/max-points-on-a-line/


class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if len(points)<2: return len(points)
        slope={}
        for i in range(len(points)):
            for j in range(i+1, len(points)):
                dy=(points[i][1]-points[j][1])
                dx=(points[i][0]-points[j][0])
                if dy==0: 
                    s='inf'
                    b=points[i][1]
                elif dx==0:
                    s=0.0
                    b=points[i][0]
                else: 
                    s=dx/float(dy)
                    b=points[i][0]-s*points[i][1]
                if (s,b) not in slope: slope[(s,b)]=set()
                #print s, b, points[i], points[j]
                slope[(s,b)].add(i)
                slope[(s,b)].add(j)
        #print slope
        maxc=max([len(s) for _,s in slope.items()])
        return maxc
