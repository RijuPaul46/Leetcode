class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        indices=[]
        nums.sort()
        for i,x in enumerate(nums):
            if x==target:
                indices.append(i)
        return indices
        