class Solution(object):
    def findDiagonalOrder(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        if not mat or not mat[0]:
            return []

        m, n = len(mat), len(mat[0])
        result_vec = []
        r, c = 0, 0
        up_down_toggle = 1

        while len(result_vec) < m * n:
            result_vec.append(mat[r][c])
            
            if up_down_toggle == 1:
                if c == n - 1:
                    r += 1
                    up_down_toggle = -1
                elif r == 0:
                    c += 1
                    up_down_toggle = -1
                else:
                    r -= 1
                    c += 1
            else:
                if r == m - 1:
                    c += 1
                    up_down_toggle = 1
                elif c == 0:
                    r += 1
                    up_down_toggle = 1
                else:
                    r += 1
                    c -= 1
        return result_vec
