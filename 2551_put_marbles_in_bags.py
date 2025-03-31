import heapq
class Solution(object):
    def putMarbles(self, w, k):
        x = [w[i]+w[i+1] for i in range(len(w)-1)]
        return sum(heapq.nlargest(k-1, x)) - sum(heapq.nsmallest(k-1, x))
