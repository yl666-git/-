from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0  # 如果prices为空，返回0利润
        
        min_price = prices[0]  # 初始买入价格
        max_profit = 0  # 初始化最大利润
        
        # 遍历价格数组
        for price in prices:
            # 计算当前价格卖出的利润
            profit = price - min_price
            max_profit = max(max_profit, profit)
            
            # 更新最小价格
            min_price = min(min_price, price)
        
        return max_profit
