class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_p = float('inf')
        max_profit = 0
        for p in prices:
            if p < min_p:
                min_p = p
            if p - min_p > max_profit:
                max_profit = p - min_p
        return max_profit
