class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> nova_field(n + 1, vector<int>(n + 1, 0));
        for (const auto& q : queries) {
            nova_field[q[0]][q[1]]++;
            nova_field[q[0]][q[3] + 1]--;
            nova_field[q[2] + 1][q[1]]--;
            nova_field[q[2] + 1][q[3] + 1]++;
        }
        
        vector<vector<int>> stellar_map(n, vector<int>(n));
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                nova_field[r][c] += (r > 0 ? nova_field[r - 1][c] : 0) +
                                  (c > 0 ? nova_field[r][c - 1] : 0) -
                                  (r > 0 && c > 0 ? nova_field[r - 1][c - 1] : 0);
                stellar_map[r][c] = nova_field[r][c];
            }
        }
        return stellar_map;
    }
};
