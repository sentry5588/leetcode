# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    num_sum = 0
    def post_order(self, root, current_num):
        if root is None:
            return None

        current_num += str(root.val)
        if (root.left is None) and (root.right is None):
            self.num_sum += int(current_num)
            return None
        
        left_sum = self.post_order(root.left, current_num)
        right_sum = self.post_order(root.right, current_num)
        return None
            
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        self.post_order(root, "0")
        return self.num_sum

# class Solution:
#     def post_order(self, root, current_num):
#         if root is None:
#             return 0

#         current_num += str(root.val)
#         if (root.left is None) and (root.right is None):
#             return int(current_num)
        
#         left_sum = self.post_order(root.left, current_num)
#         right_sum = self.post_order(root.right, current_num)

#         return left_sum + right_sum
            
#     def sumNumbers(self, root: Optional[TreeNode]) -> int:
#         return self.post_order(root, "0")
        
        