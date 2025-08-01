class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        pyramid = []
        for i in range(numRows):
            row = [None] * (i + 1)
            row[0], row[-1] = 1, 1
            for j in range(1, i):
                row[j] = pyramid[i - 1][j - 1] + pyramid[i - 1][j]
            pyramid.append(row)
        return pyramid
