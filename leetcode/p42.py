# 42. Trapping Rain Water
# https://leetcode.com/problems/trapping-rain-water/

class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        stack=[]
        s=0
        h=0
        for i, v in enumerate(height):
            #print i, v, stack, s
            if v>0:
                while stack:
                    if stack[-1][0]<=v:
                        vv, ni=stack.pop()
                        #print '@', (i-ni-1)*(vv-h)
                        s+=(i-ni-1)*(vv-h)
                        h=vv
                    else:
                        vv, ni=stack[-1]
                        #print (i-ni-1)*(v-h)
                        s+=(i-ni-1)*(v-h)
                        break
                h=0
                stack.append((v, i))
        return s
