# -*- coding:UTF-8 -*-
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :ret-type: List[int]
        """
        lenth = len(nums)
        devia = 0
        for num in nums:
            devia += 1
            for i in range(devia, lenth):
                # if lenth=n, let num from devia to n-1 in nums
                if target == (num + nums[i]):
                    return nums.index(num), i
