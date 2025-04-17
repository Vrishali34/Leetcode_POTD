class Solution(object):
    def countPairs(self, w, z):
        return sum(w[i]==w[j] and (i*j)%z==0 for i in range(len(w)) for j in range(i+1, len(w)))
