class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        f = [0]*10
        for d in digits: f[d] += 1
        res = []
        for i in xrange(100, 1000, 2):
            a, b, c = i//100, (i//10)%10, i%10
            f[a] -= 1; f[b] -= 1; f[c] -= 1
            if f[a] >= 0 and f[b] >= 0 and f[c] >= 0: res.append(i)
            f[a] += 1; f[b] += 1; f[c] += 1
        return res
