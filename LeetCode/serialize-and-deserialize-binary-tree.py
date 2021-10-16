# 297. Serialize and Deserialize Binary Tree
import json


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        result = {}
        def traversal(node, result, pos: int):
            if node is None:
                return
            result[pos] = node.val
            if node.left is not None:
                traversal(node.left, result, 2 * pos)
            if node.right is not None:
                traversal(node.right, result, 2 * pos + 1)
                
        traversal(root, result, 1)
        return json.dumps(result)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        data = json.loads(data)
        def traversal(data, pos: int):
            node = TreeNode(data[str(pos)])
            if str(2 * pos) in data:
                node.left = traversal(data, 2 * pos)
            if str(2 * pos + 1) in data:
                node.right = traversal(data, 2 * pos + 1)
            return node
        
        if len(data) == 0:
            return
        return traversal(data, 1)

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))