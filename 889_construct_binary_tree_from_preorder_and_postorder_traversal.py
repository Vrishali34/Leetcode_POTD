class Solution:
    def constructFromPrePost(self, p, q):
        if not p: return None
        n = TreeNode(p[0])
        if len(p) == 1: return n
        d = q.index(p[1])
        n.left = self.constructFromPrePost(p[1:d+2], q[:d+1])
        n.right = self.constructFromPrePost(p[d+2:], q[d+1:-1])
        return n
