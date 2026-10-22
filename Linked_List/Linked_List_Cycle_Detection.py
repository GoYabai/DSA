# Hash map

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        visited = {}
        temp = head
        while temp:
            if temp not in visited:
                visited[temp] = visited.get(temp, 0) + 1
            else:
                return True
            temp = temp.next
        return False


# Two pointer

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow, fast = head, head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False