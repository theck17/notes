class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        for i in range(nums.count(val)):
            valIndex = nums.index(val)
            del nums[valIndex]
        return len(nums)

if __name__ == '__main__':
    pass