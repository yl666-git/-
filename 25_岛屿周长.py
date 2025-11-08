from typing import List
#数学法
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:

        num = 0
        cover = 0

        nr, nc = len(grid), len(grid[0])

        for r in range(nr):
            for c in range(nc):

                if grid[r][c] == 1:
                    num += 1

                    if r-1 >= 0 and grid[r-1][c]==1:
                        cover += 1
                    if c-1 >= 0 and grid[r][c-1]==1:
                        cover += 1

        return num * 4 - cover * 2 



#粗暴遍历找边法：
class Solution:
    def islandPerimeter(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        ans = 0
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                if x == 0:
                    continue
                if i == 0 or grid[i - 1][j] == 0:  # 上：出界或者是水
                    ans += 1
                if i == m - 1 or grid[i + 1][j] == 0:  # 下：出界或者是水
                    ans += 1
                if j == 0 or row[j - 1] == 0:  # 左：出界或者是水
                    ans += 1
                if j == n - 1 or row[j + 1] == 0:  # 右：出界或者是水
                    ans += 1
        return ans