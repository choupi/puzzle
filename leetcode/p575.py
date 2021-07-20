class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        type_cnt = len(set(candyType))
        candy_cnt = len(candyType)
        return min(type_cnt, candy_cnt//2)
