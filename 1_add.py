from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()  # 创建一个空字典（哈希表），用来存储已访问的数字和它们的索引
        for i, num in enumerate(nums):  # 遍历整个列表，i 是索引，num 是当前数字
            if target - num in hashtable:  # 检查 (target - num) 是否存在于 hashtable 中
                return [hashtable[target - num], i]  # 如果存在，返回对应的两个索引
            hashtable[nums[i]] = i  # 如果没有找到，记录当前数字和它的索引到哈希表中
        return []  # 如果循环结束仍未找到答案，返回空列表（这种情况在题目中假定不会出现）

# 创建 Solution 类的实例
solution = Solution()

# 定义一个数字数组和目标值
nums = [2, 7, 11, 15]
target = 9

# 调用 twoSum 函数
result = solution.twoSum(nums, target)

# 打印结果
print(f"两个数的索引是: {result}")
