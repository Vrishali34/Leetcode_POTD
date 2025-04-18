class Solution(object):
    def countAndSay(self, n):
        z = "1"
        for _ in range(n - 1):
            t, u = "", 0
            while u < len(z):
                v = u
                while v < len(z) and z[u] == z[v]: v += 1
                t += str(v - u) + z[u]
                u = v
            z = t
        return z
