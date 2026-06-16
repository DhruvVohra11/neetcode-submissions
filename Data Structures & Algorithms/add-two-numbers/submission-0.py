# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        
        x1 = l1
        x2 = l2
        n1 = 0
        n2 = 0
        i = 0

        while x1:
            n1 += (10**i)*x1.val
            i+=1
            x1 = x1.next
         
        i = 0 

        while x2:
            n2 += (10**i)*x2.val
            i+=1
            x2 = x2.next
        
        num = n1+n2

        if num == 0:
            return ListNode(0)

        dummy = ListNode(-1) # Acts as a permanent anchor to the start of the list
        curr = dummy         # This pointer will move forward to build the list

        while num > 0:
            digit = num % 10
            curr.next = ListNode(digit) 
            curr = curr.next            
            num = num // 10
        
        return dummy.next # dummy.next points to the actual head of our new list