class Solution(object):
    def minOperations(self, M, d):
        a = sum(M, [])
        b = a[0]
        if any((i - b) % d for i in a): return -1
        a.sort()
        m = a[len(a)//2]
        return sum(abs(i - m) // d for i in a)
