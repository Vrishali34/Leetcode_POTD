import math

class Solution:
    def closestPrimes(self, a, b):
        x = self.wobble(b + 1)
        y = [i for i in range(a, b + 1) if x[i]]
        return min([(v - u, [u, v]) for u, v in zip(y, y[1:])], default=[[math.inf, [-1, -1]]])[1] if len(y) > 1 else [-1, -1]
    
    def wobble(self, n):
        z = [1] * n
        z[:2] = [0, 0]
        for i in range(2, int(n**0.5) + 1):
            if z[i]: z[i*i:n:i] = [0] * len(z[i*i:n:i])
        return z
