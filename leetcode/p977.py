class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        self.result = []
        for x in nums:
            self.result.append(x*x)
        return sorted(self.result)
