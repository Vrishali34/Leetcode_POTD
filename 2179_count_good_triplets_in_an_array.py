class Solution(object):
    def goodTriplets(self, nums1, nums2):
        n = len(nums1)
        pos = [0] * n
        for i in range(n):
            pos[nums1[i]] = i
        mapped = [pos[x] for x in nums2]

        bit1 = BIT(n)
        left = [0] * n
        for i in range(n):
            left[i] = bit1.query(mapped[i])
            bit1.update(mapped[i] + 1, 1)

        bit2 = BIT(n)
        right = [0] * n
        for i in range(n - 1, -1, -1):
            right[i] = bit2.query(n) - bit2.query(mapped[i] + 1)
            bit2.update(mapped[i] + 1, 1)

        ans = 0
        for i in range(n):
            ans += left[i] * right[i]
        return ans

class BIT:
    def __init__(self, size):
        self.tree = [0] * (size + 2)
        self.n = size + 2

    def update(self, i, val):
        while i < self.n:
            self.tree[i] += val
            i += i & -i

    def query(self, i):
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res
