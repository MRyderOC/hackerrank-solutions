class Node:
    def __init__(self, data):
        self.right = self.left = None
        self.data = data


class Solution:
    def insert(self, root, data):
        if root is None:
            return Node(data)
        else:
            if data <= root.data:
                cur = self.insert(root.left, data)
                root.left = cur
            else:
                cur = self.insert(root.right, data)
                root.right = cur
        return root

    def levelOrder(self, root):
        # Write your code here
        bfs = []
        q = [root]
        while q:
            popped = q.pop(0)
            bfs.append(popped.data)
            if popped.left:
                q.append(popped.left)
            if popped.right:
                q.append(popped.right)

        print(" ".join(list(map(str, bfs))))


T = int(input())
myTree = Solution()
root = None
for i in range(T):
    data = int(input())
    root = myTree.insert(root, data)
myTree.levelOrder(root)
