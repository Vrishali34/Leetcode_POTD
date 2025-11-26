class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int matrix_h = grid.size();
        int matrix_w = grid[0].size();
        int mod_const = 1e9 + 7;
        vector<vector<int>> mod_bucket(matrix_w, vector<int>(k, 0));

        for (int i_val = 0; i_val < matrix_h; ++i_val) {
            for (int j_val = 0; j_val < matrix_w; ++j_val) {
                vector<int> temp_bucket(k, 0);
                int curr_mod = grid[i_val][j_val] % k;
                
                if (i_val == 0 && j_val == 0) {
                    mod_bucket[0][curr_mod] = 1;
                    continue;
                }

                for (int r_val = 0; r_val < k; ++r_val) {
                    int src_rem = (r_val - curr_mod + k) % k;
                    long long path_sum = 0;
                    
                    if (i_val > 0) path_sum += mod_bucket[j_val][src_rem];
                    if (j_val > 0) path_sum += mod_bucket[j_val - 1][src_rem];
                    
                    temp_bucket[r_val] = path_sum % mod_const;
                }
                mod_bucket[j_val] = temp_bucket;
            }
        }
        return mod_bucket[matrix_w - 1][0];
    }
};
