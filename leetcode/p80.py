class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l = len(nums)
        if l<1: return 0
        i = 1
        j = 0
        t = 1
        while i<l:
            if nums[i] == nums[i-1]:
                t += 1
            else:
                c = min(t, 2)
                while c>0:
                    nums[j] = nums[i-1]
                    j+=1
                    c-=1
                t = 1
            i += 1
        c = min(t, 2)
        while c>0:
            nums[j] = nums[i-1]
            j+=1
            c-=1
        return j
