
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None



class Solution:

    def slove(self, root, lst):
        if not root:
            return
        lst.append(str(root.val))
        if not root.left and not root.right:
            self.ans.append("->".join(lst))
        self.slove(root.left, lst)
        self.slove(root.right, lst)
        lst.pop()



    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        self.ans = []
        self.slove(root, [])
        return self.ans

if __name__ == '__main__':
    slu = Solution()
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.right = TreeNode(5)
    root.right = TreeNode(3)
    print slu.binaryTreePaths(root)
