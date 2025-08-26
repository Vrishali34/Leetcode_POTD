class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long best_diag_sq = 0;
        int best_region = 0;
        for (auto& dim_pair : dimensions) {
            long long current_diag_sq = static_cast<long long>(dim_pair[0]) * dim_pair[0] + static_cast<long long>(dim_pair[1]) * dim_pair[1];
            int current_region = dim_pair[0] * dim_pair[1];
            if (current_diag_sq > best_diag_sq) {
                best_diag_sq = current_diag_sq;
                best_region = current_region;
            } else if (current_diag_sq == best_diag_sq && current_region > best_region) {
                best_region = current_region;
            }
        }
        return best_region;
    }
};
