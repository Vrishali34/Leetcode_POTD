class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        c = Counter(digits)
        r = []
        for i in range(100, 1000, 2):
            x, y, z = i // 100, (i // 10) % 10, i % 10
            cnt = Counter([x, y, z])
            if all(c[d] >= cnt[d] for d in cnt):
                r.append(i)
        return r
