import heapq
class Solution(object):
    def minTimeToReach(self, z):
        X, Y = len(z), len(z[0])
        H = [(0, 0, 0, 1)]
        S = set()
        J = [(-1,0),(1,0),(0,-1),(0,1)]
        while H:
            T, i, j, d = heapq.heappop(H)
            if (i,j) in S: continue
            if i == X-1 and j == Y-1: return T
            S.add((i,j))
            for a,b in J:
                ni, nj = i+a, j+b
                if 0<=ni<X and 0<=nj<Y and (ni,nj) not in S:
                    nt = max(T, z[ni][nj]) + d
                    heapq.heappush(H, (nt, ni, nj, 3-d))
        return -1
