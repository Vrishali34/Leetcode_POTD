class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int row_limit = coins.size(), col_limit = coins[0].size();
        vector<vector<vector<long long>>> path_cache(row_limit, vector<vector<long long>>(col_limit, vector<long long>(3, -1e18)));
        for (int k_idx = 0; k_idx < 3; ++k_idx) {
            path_cache[0][0][k_idx] = coins[0][0];
            if (k_idx > 0 && coins[0][0] < 0) path_cache[0][0][k_idx] = 0;
        }
        for (int r = 0; r < row_limit; ++r) {
            for (int c = 0; c < col_limit; ++c) {
                for (int k = 0; k < 3; ++k) {
                    if (r > 0) {
                        path_cache[r][c][k] = max(path_cache[r][c][k], path_cache[r - 1][c][k] + coins[r][c]);
                        if (k > 0 && coins[r][c] < 0) path_cache[r][c][k] = max(path_cache[r][c][k], path_cache[r - 1][c][k - 1]);
                    }
                    if (c > 0) {
                        path_cache[r][c][k] = max(path_cache[r][c][k], path_cache[r][c - 1][k] + coins[r][c]);
                        if (k > 0 && coins[r][c] < 0) path_cache[r][c][k] = max(path_cache[r][c][k], path_cache[r][c - 1][k - 1]);
                    }
                }
            }
        }
        return path_cache[row_limit - 1][col_limit - 1][2];
    }
};
