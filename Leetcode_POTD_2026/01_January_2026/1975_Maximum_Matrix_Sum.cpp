class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long net_sum = 0;
        int min_val = INT_MAX, neg_qty = 0;
        for (auto& row_vec : matrix) {
            for (int cell_val : row_vec) {
                net_sum += abs(cell_val);
                if (cell_val < 0) neg_qty++;
                min_val = min(min_val, abs(cell_val));
            }
        }
        return (neg_qty % 2 == 0) ? net_sum : net_sum - 2LL * min_val;
    }
};
