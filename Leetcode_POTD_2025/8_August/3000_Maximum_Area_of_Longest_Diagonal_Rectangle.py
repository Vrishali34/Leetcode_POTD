class Solution(object):
    def areaOfMaxDiagonal(self, dimensions):
        top_diag_sq, max_field = 0, 0
        for shape in dimensions:
            current_diag_sq = shape[0] * shape[0] + shape[1] * shape[1]
            current_field = shape[0] * shape[1]
            if current_diag_sq > top_diag_sq:
                top_diag_sq, max_field = current_diag_sq, current_field
            elif current_diag_sq == top_diag_sq:
                max_field = max(max_field, current_field)
        return max_field
