class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        dups = set()
        for x in nums:
            if x not in dups:
                dups.add(x)
            else :
                return x
        return -9999