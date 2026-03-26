class Solution {
    bool isValid(unordered_map<long long, int>& counts, vector<vector<int>>& grid, int r1, int r2, int c1, int c2, long long gap) {
        int h = r2 - r1 + 1, w = c2 - c1 + 1;
        if (h * w == 1) return false;
        if (h == 1) return (grid[r1][c1] == gap || grid[r1][c2] == gap);
        if (w == 1) return (grid[r1][c1] == gap || grid[r2][c1] == gap);
        return counts[gap] > 0;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        long long total = 0;
        for (auto& row : grid) for (int x : row) total += x;

        long long upper = 0;
        unordered_map<long long, int> upFrq, lowFrq;
        for (auto& r : grid) for (int x : r) lowFrq[x]++;

        for (int i = 0; i < R - 1; ++i) {
            for (int j = 0; j < C; ++j) {
                int v = grid[i][j];
                upper += v;
                upFrq[v]++;
                if (--lowFrq[v] == 0) lowFrq.erase(v);
            }
            long long lower = total - upper;
            if (upper == lower) return true;
            if (upper > lower && isValid(upFrq, grid, 0, i, 0, C - 1, upper - lower)) return true;
            if (lower > upper && isValid(lowFrq, grid, i + 1, R - 1, 0, C - 1, lower - upper)) return true;
        }

        long long left = 0;
        unordered_map<long long, int> lFrq, rFrq;
        for (auto& r : grid) for (int x : r) rFrq[x]++;

        for (int j = 0; j < C - 1; ++j) {
            for (int i = 0; i < R; ++i) {
                int v = grid[i][j];
                left += v;
                lFrq[v]++;
                if (--rFrq[v] == 0) rFrq.erase(v);
            }
            long long right = total - left;
            if (left == right) return true;
            if (left > right && isValid(lFrq, grid, 0, R - 1, 0, j, left - right)) return true;
            if (right > left && isValid(rFrq, grid, 0, R - 1, j + 1, C - 1, right - left)) return true;
        }
        return false;
    }
};
