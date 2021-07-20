class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if not nums:
            return False
        self.max_n1 = nums[0]
        self.max_n2 = None
        for n in nums:
            if self.max_n2 is not None and n > self.max_n2:
                return True
            if n > self.max_n1:
                self.max_n2 = n
            if n < self.max_n1:
                self.max_n1 = n
        return False
