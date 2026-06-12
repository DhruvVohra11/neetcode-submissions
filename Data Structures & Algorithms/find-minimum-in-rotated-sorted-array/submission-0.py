import math 
class Solution:
    def findMin(self, nums: List[int]) -> int:
        # if we make a Binary tree from this array -> find the left most element and done
        n = len(nums)-1
        if nums[n] < nums[0]:
            l = 0
            r = n 
            mid = (l+r) // 2
            while l < r:
                if nums[mid]>nums[r]:
                    l = mid+1
                    mid = (l+r)//2
                else :
                    r = mid
                    mid = (l+r)//2
            return nums[mid]
        else :
            return nums[0]
                
