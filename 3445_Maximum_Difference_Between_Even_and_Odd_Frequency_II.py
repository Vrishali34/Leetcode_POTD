class Solution(object):
    def maxDifference(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        arr = list(map(int, s))
        INF = float('inf')
        ans = -INF
        
        for a in range(5):
            for b in range(5):
                if a == b:
                    continue
                curA = curB = 0
                preA = preB = 0
                t = [[INF, INF], [INF, INF]]
                l = -1
                
                for r, x in enumerate(arr):
                    curA += (x == a)
                    curB += (x == b)
                    
                    while r - l >= k and curB - preB >= 2:
                        t[preA & 1][preB & 1] = min(t[preA & 1][preB & 1], preA - preB)
                        l += 1
                        preA += (arr[l] == a)
                        preB += (arr[l] == b)
                    
                    ans = max(ans, curA - curB - t[(curA & 1) ^ 1][curB & 1])
        
        return ans
