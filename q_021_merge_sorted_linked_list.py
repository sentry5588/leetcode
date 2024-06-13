# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list2 == None:
            return list1
        if list1 == None:
            return list2
            
        # None of them are empty
        if list1.val <= list2.val:
            head = list1
            list1 = list1.next
        else:
            head = list2
            list2 = list2.next
        
        current_node = head
        while list1 != None and list2 != None:
            # print(f'{head=}')
            # print(f'{list1=}')
            # print(f'{list2=}')
            if list1.val <= list2.val:
                current_node.next = list1
                list1 = list1.next
            else:
                current_node.next = list2
                list2 = list2.next
            current_node = current_node.next

        if list1 == None:
            current_node.next = list2
        if list2 == None:
            current_node.next = list1
        
        return head

        