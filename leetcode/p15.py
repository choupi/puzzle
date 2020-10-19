# 15. 3Sum
# https://leetcode.com/problems/3sum/


class Solution(object):
    def binary_search(self, nums, s, st, ed):
        #st=0
        #ed=len(nums)
        while st<ed:
            #print st, ed
            i=(ed+st)/2
            if nums[i]+s==0: return i
            elif nums[i]+s>0: ed=i
            elif nums[i]+s<0: st=i+1
        return None
            
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        sol_set=set()

        num_set={}
        for i,v in enumerate(nums): num_set[v]=num_set.get(v,0)+1
        sorted_nums=[]
        for v,c in num_set.items():
            sorted_nums+=[v]*min(2,num_set[v])
        sorted_nums=sorted(sorted_nums)
        #print sorted_nums
        for i in range(len(sorted_nums)):
            for j in range(len(sorted_nums)-1, i, -1):
                #if sorted_nums[i]+sorted_nums[j]+sorted_nums[j-1] <0: break
                #if sorted_nums[i]+sorted_nums[j]+sorted_nums[i+1] >0: break
                #k=self.binary_search(sorted_nums, sorted_nums[i]+sorted_nums[j], i+1, j)
                #if not k or k==i or k==j: continue
                k=num_set.get(0-sorted_nums[i]-sorted_nums[j], None)
                if not k: continue
                k=0-sorted_nums[i]-sorted_nums[j]
                sol_set.add(','.join(sorted([str(sorted_nums[x]) for x in [i,j]]+[str(k)])))
        sols=[]
        for x in sol_set:
            a=[int(xx) for xx in x.split(',')]
            flag=True
            ad={}
            for aa in a: ad[aa]=ad.get(aa,0)+1
            for aa in ad:
                if num_set[aa]<ad[aa]:
                    flag=False
                    break
            if flag: sols.append(a)
        #return [[int(xx) for xx in x.split(',')] for x in sol_set]
        return sols
