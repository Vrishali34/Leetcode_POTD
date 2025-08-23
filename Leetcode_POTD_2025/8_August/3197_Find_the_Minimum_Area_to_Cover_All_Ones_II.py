class Solution(object):
    def minimumSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        rows, cols = len(grid), len(grid[0])
        min_total_area = float('inf')

        def calculate_area(r1, c1, r2, c2):
            min_row, max_row = rows, -1
            min_col, max_col = cols, -1
            has_one = False
            for r in range(r1, r2 + 1):
                for c in range(c1, c2 + 1):
                    if grid[r][c] == 1:
                        min_row = min(min_row, r)
                        max_row = max(max_row, r)
                        min_col = min(min_col, c)
                        max_col = max(max_col, c)
                        has_one = True
            if not has_one:
                return 0
            return (max_row - min_row + 1) * (max_col - min_col + 1)

        # Case 1: Three horizontal slices
        for r1 in range(rows - 1):
            for r2 in range(r1 + 1, rows - 1):
                area1 = calculate_area(0, 0, r1, cols - 1)
                area2 = calculate_area(r1 + 1, 0, r2, cols - 1)
                area3 = calculate_area(r2 + 1, 0, rows - 1, cols - 1)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

        # Case 2: Three vertical slices
        for c1 in range(cols - 1):
            for c2 in range(c1 + 1, cols - 1):
                area1 = calculate_area(0, 0, rows - 1, c1)
                area2 = calculate_area(0, c1 + 1, rows - 1, c2)
                area3 = calculate_area(0, c2 + 1, rows - 1, cols - 1)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

        # Case 3: One horizontal, then one vertical split
        for r_split in range(rows - 1):
            for c_split in range(cols - 1):
                area1 = calculate_area(0, 0, r_split, cols - 1)
                area2 = calculate_area(r_split + 1, 0, rows - 1, c_split)
                area3 = calculate_area(r_split + 1, c_split + 1, rows - 1, cols - 1)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

                area1 = calculate_area(r_split + 1, 0, rows - 1, cols - 1)
                area2 = calculate_area(0, 0, r_split, c_split)
                area3 = calculate_area(0, c_split + 1, r_split, cols - 1)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

        # Case 4: One vertical, then one horizontal split
        for c_split in range(cols - 1):
            for r_split in range(rows - 1):
                area1 = calculate_area(0, 0, rows - 1, c_split)
                area2 = calculate_area(0, c_split + 1, r_split, cols - 1)
                area3 = calculate_area(r_split + 1, c_split + 1, rows - 1, cols - 1)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

                area1 = calculate_area(0, c_split + 1, rows - 1, cols - 1)
                area2 = calculate_area(0, 0, r_split, c_split)
                area3 = calculate_area(r_split + 1, 0, rows - 1, c_split)
                if area1 > 0 and area2 > 0 and area3 > 0:
                    min_total_area = min(min_total_area, area1 + area2 + area3)

        return min_total_area
