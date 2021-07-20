import random
class Solution:

    def __init__(self, nums: List[int]):
        self.num_dict = {}
        for i, n in enumerate(nums):
            a = self.num_dict.get(n, [])
            a.append(i)
            self.num_dict[n] = a

    def pick(self, target: int) -> int:
        return random.choice(self.num_dict[target])


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
