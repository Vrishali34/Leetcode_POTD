class Solution(object):
    def lcaDeepestLeaves(self, root):
        class R:
            def __init__(s, d=0, n=None): s.d, s.n = d, n
        def g(n):
            if not n: return R()
            l, r = g(n.left), g(n.right)
            return R(l.d + 1, l.n) if l.d > r.d else R(r.d + 1, r.n) if r.d > l.d else R(l.d + 1, n)
        return g(root).n
