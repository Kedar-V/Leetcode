'''Recursion with Memoisation'''
class Solution:

    # True = Buy
    # False = Sell
    def helper(self, prices, curr_day, action, n, k):

        if curr_day == n or k == 0:
            return 0

        if (curr_day, action, k) in self.memoization.keys():
            return self.memoization[(curr_day, action, k)]

        max_profit = 0
        
        # If buying
        if action:
            buy = self.helper(prices, curr_day+1, not action, n, k) - prices[curr_day]
            not_buy = self.helper(prices, curr_day+1, action, n, k)
            curr_profit = max(buy, not_buy)
        else:
            sell = self.helper(prices, curr_day+1, not action, n, k-1) + prices[curr_day]
            not_sell = self.helper(prices, curr_day+1, action, n, k)
            curr_profit = max(sell, not_sell)

        max_profit = max(max_profit, curr_profit)
        
        self.memoization[(curr_day, action, k)] = max_profit
        return max_profit

    def maxProfit(self, k: int, prices):
        
        self.memoization = {}
        n = len(prices)
        profit = self.helper(prices, 0, True, n, k)
        return profit
