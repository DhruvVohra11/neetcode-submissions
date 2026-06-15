# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        x1 = head 
        i = 0 
        while x1:
            i += 1
            if i>1000:
                return True
            x1 = x1.next
        return False