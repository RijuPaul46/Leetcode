# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    # def solve(self,node):
    #     if(node.left==None and node.right==None):
    #         return node
    #     left=self.solve(node.left)
    #     temp=left
    #     while temp.right !=None:
    #         temp=temp.right
    #     right=self.solve(node.right)
    #     node.right=left
    #     temp.right=right
    #     return node

        

    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        curr=root
        while curr:
            if(curr.left):
                pred=curr.left
                while pred.right:
                    pred=pred.right
                pred.right=curr.right
                temp=curr.left
                curr.right=curr.left
                curr.left=None
                curr=temp
            else:
                curr=curr.right

        