class Solution:

    def __init__(self, nums: List[int]):
        self.shuffled = nums[::]
        self.nums = nums[::]

    def reset(self) -> List[int]:
        """
        Resets the array to its original configuration and return it.
        """
        return self.nums

    def shuffle(self) -> List[int]:
        """
        Returns a random shuffling of the array.
        """
        for i in range(len(self.shuffled)):
            n = random.randint(0, i)
            t = self.shuffled[n]
            self.shuffled[n] = self.shuffled[i]
            self.shuffled[i] = t
        return self.shuffled

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()
