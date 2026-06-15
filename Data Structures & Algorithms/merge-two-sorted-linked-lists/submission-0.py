# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        
        # make two queues 

        q1 = deque()
        q2 = deque()

        l1 = list1
        while l1:
            q1.append(l1)
            l1 = l1.next
            
        
        l2 = list2
        while l2:
            q2.append(l2)
            l2 = l2.next
        
        # now compare top values and then see which is smaller and pop
        dummy = ListNode(-1)
        tail = dummy
        

        while q1 and q2:
            if q1[0].val < q2[0].val:
                node = q1.popleft()
                
            else :
                node = q2.popleft()

            tail.next = node  # Stitch the node to our new list
            tail = tail.next  # Move the tail forward
        
        # If there are any remaining nodes in either queue, stitch them to the end
        if q1:
            tail.next = q1[0]
        elif q2:
            tail.next = q2[0]
            
        return dummy.next



            



