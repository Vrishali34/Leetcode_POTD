class Solution(object):
    def countFairPairs(self, a, p, q):
        a.sort()
        return self.g(a, q) - self.g(a, p - 1)
    
    def g(self, b, t):
        z, j = 0, len(b) - 1
        for i in range(len(b)):
            while i < j and b[i] + b[j] > t:
                j -= 1
            if i < j:
                z += j - i
        return z
