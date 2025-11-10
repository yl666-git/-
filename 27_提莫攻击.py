from typing import List

class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        time = 0
        for i, t in enumerate(timeSeries):
            if i == 0:
                i += 1
            elif timeSeries[i] - timeSeries[i-1] <= duration:
                time = time + timeSeries[i] - timeSeries[i-1]
                i += 1
            else:
                time += duration
        
        time += duration
        return time


# 优化方法：
class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        ans, expired = 0, 0
        for i in range(len(timeSeries)):
         if timeSeries[i] >= expired:
                ans += duration
        else:
            ans += timeSeries[i] + duration - expired
        expired = timeSeries[i] + duration
        return ans