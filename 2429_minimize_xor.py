class Solution(object):
    def minimizeXor(self, m, n):
        req = bin(n).count('1')
        res = 0
        for i in range(31, -1, -1):
            if req and (m & (1 << i)):
                res |= (1 << i)
                req -= 1
        for i in range(32):
            if req and not (res & (1 << i)):
                res |= (1 << i)
                req -= 1
        return res
