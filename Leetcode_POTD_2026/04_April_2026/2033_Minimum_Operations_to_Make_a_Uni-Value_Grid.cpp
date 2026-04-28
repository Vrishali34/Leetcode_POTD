class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat_list;
        for (const auto& row_vec : grid) 
            for (int cell_val : row_vec) flat_list.push_back(cell_val);
        
        sort(flat_list.begin(), flat_list.end());
        int mid_val = flat_list[flat_list.size() / 2];
        int total_ops = 0;

        for (int item : flat_list) {
            if ((item - mid_val) % x != 0) return -1;
            total_ops += abs(item - mid_val) / x;
        }
        return total_ops;
    }
};
