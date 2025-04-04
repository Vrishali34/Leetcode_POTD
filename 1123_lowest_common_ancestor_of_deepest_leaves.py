class Solution(object):
    def lcaDeepestLeaves(self, root):
        def z(n):
            if not n: return 0, None
            l, x = z(n.left)
            r, y = z(n.right)
            return (l + 1, x) if l > r else (r + 1, y) if r > l else (l + 1, n)
        return z(root)[1]
