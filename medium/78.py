class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        numsSize = len(nums)
        power_set = []
        power_set.append([])

        for num in nums:
            for element in power_set.copy():
                new_element = element.copy()
                new_element.append(num)
                power_set.append(new_element)
                print(power_set)
        return power_set