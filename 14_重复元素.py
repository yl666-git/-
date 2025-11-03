from typing import List

#set()函数用于创建一个无序不重复元素集合，可以用来去除列表中的重复元素
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) < len(nums)

