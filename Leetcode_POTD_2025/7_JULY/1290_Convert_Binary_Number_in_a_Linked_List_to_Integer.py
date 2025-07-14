# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def getDecimalValue(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        stellar_val = 0
        while head:
            stellar_val = (stellar_val << 1) | head.val
            head = head.next
        return stellar_val
