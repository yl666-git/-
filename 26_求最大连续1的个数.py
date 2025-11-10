from typing import List

class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        count = []
        n = len(nums)
        left = right = 0
        while right < n:
            if nums[right] == 0:
                count.append(right - left)
                left = right + 1
                right = left
            elif nums[right] == 1:
                right += 1
        count.append(right - left)
        return max(count)


#优化方法：
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maxCount = count = 0

        for i, num in enumerate(nums):
            if num == 1:
                count += 1
            else:
                maxCount = max(maxCount, count)
                count = 0
        
        maxCount = max(maxCount, count)
        return maxCount




        