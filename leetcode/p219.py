class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        if not nums or k < 1:
            return False
        kset = set()
        i = 0
        j = 1
        kset.add(nums[0])
        while j < len(nums):
            #print(nums[j], kset)
            if nums[j] in kset:
                return True
            kset.add(nums[j])
            j += 1
            if len(kset) > k:
                kset.remove(nums[i])
                i += 1
        return False
