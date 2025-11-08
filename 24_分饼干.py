from typing import List

class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # 1. 排序（核心：小饼干满足小贪心，最大化满足数量）
        g.sort()
        s.sort()
        
        i = j = count = 0
        len_g, len_s = len(g), len(s)
        
        # 2. 循环条件：同时不越界（i<孩子数，j<饼干数）
        while i < len_g and j < len_s:
            if s[j] >= g[i]:
                # 饼干能满足当前孩子，双方都往后移
                count += 1
                i += 1
                j += 1
            else:
                # 饼干太小，换更大的饼干
                j += 1
        return count