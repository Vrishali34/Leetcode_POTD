class Solution(object):
    def countGoodNumbers(self, n):
        return self.q(5, (n+1)//2) * self.q(4, n//2) % P
    def q(self, a, b):
        return 1 if b == 0 else self.q(a*a%P, b//2) * (a if b%2 else 1) % P
P = 10**9 + 7
