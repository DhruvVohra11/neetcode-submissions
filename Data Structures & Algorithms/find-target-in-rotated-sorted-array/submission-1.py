from typing import List

class Solution:
    def bsearch(self, nums: List[int], l: int, r: int, t: int) -> int:
        # Base case: if pointers cross, the target isn't in this segment
        if l > r: 
            return -1
            
        mid = (l + r) // 2
        if t > nums[mid]:
            return self.bsearch(nums, mid + 1, r, t)  # Added 'return' and 'self.'
        elif t < nums[mid]:
            return self.bsearch(nums, l, mid - 1, t)  # Added 'return', 'self.', and changed mid to mid-1
        elif t == nums[mid]:
            return mid
        return -1

    def search(self, nums: List[int], target: int) -> int:
        n = len(nums) - 1
        if nums[n] >= nums[0]: # Handled arrays of length 1 with >=
            ans = self.bsearch(nums, 0, n, target)
            return ans
        else:
            l = 0 
            r = n
            # Correctly finding the pivot index where rotation happens
            while l < r:
                mid = (l + r) // 2
                if nums[mid] > nums[r]: # Compare with right boundary to find the drop point
                    l = mid + 1
                else:
                    r = mid
            
            # l is now the pivot index (the smallest element)
            # Search both halves using original global indices, without slicing
            a1 = self.bsearch(nums, 0, l - 1, target)
            a2 = self.bsearch(nums, l, n, target)
            
            # If it's found in the first half, return it. Otherwise, return the second half's result
            if a1 != -1:
                return a1
            else: 
                return a2