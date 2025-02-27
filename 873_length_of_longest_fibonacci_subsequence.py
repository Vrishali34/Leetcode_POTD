class Solution(object):
    def lenLongestFibSubseq(self, arr):
        d, mx = {v: i for i, v in enumerate(arr)}, 0
        for i in range(len(arr)):
            for j in range(i+1, len(arr)):
                mx = max(mx, 2 + self.fibSeq(arr, arr[i], arr[j], d))
        return mx if mx > 2 else 0

    def fibSeq(self, arr, a, b, d):
        return 1 + self.fibSeq(arr, b, a+b, d) if a+b in d else 0
