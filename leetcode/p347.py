class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        num_dict = {}
        for i in nums:
            num_dict[i] = num_dict.get(i, 0) + 1
        return sorted(num_dict, key=num_dict.get, reverse=True)[:k]
