class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        trans = False
        buy_price = None
        profit = 0
        for i in range(len(prices)):
            if trans:
                if i == len(prices)-1 or prices[i+1]<prices[i]:
                    profit += prices[i] - buy_price
                    trans = False
            else:
                if i<len(prices)-1 and prices[i+1]>prices[i]:
                    buy_price = prices[i]
                    trans = True
        return profit
