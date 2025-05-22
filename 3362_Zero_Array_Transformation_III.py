class Solution(object):
    def maxRemoval(self, a, b):
        n, m, j, s, c = len(a), len(b), 0, 0, 0
        d = [0] * (n + 2)
        b.sort()
        import heapq
        q = []
        for i in range(n):
            while j < m and b[j][0] <= i:
                heapq.heappush(q, -b[j][1])
                j += 1
            while s < a[i]:
                if not q or -q[0] < i: return -1
                r = -heapq.heappop(q)
                d[i] += 1
                d[r + 1] -= 1
                s += 1
                c += 1
            s += d[i + 1]
        return m - c
