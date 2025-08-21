class Solution(object):
    def numSubmat(self, mat):
        rows = len(mat)
        cols = len(mat[0])
        heights = [[0] * cols for _ in range(rows)]
        for i in range(rows):
            for j in range(cols):
                if mat[i][j] == 1:
                    heights[i][j] = heights[i - 1][j] + 1 if i > 0 else 1
        total = 0
        for i in range(rows):
            stack = []
            count = 0
            for j in range(cols):
                h = heights[i][j]
                while stack and stack[-1][0] > h:
                    stack.pop()
                prev_count = stack[-1][1] if stack else 0
                current_count = h * (j - (stack[-1][2] if stack else -1)) + prev_count
                total += current_count
                stack.append([h, current_count, j])
        return total
