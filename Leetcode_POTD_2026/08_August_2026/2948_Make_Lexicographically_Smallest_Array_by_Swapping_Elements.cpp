class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int elem_cnt = nums.size();
        vector<int> idx_order(elem_cnt);
        iota(idx_order.begin(), idx_order.end(), 0);
        sort(idx_order.begin(), idx_order.end(), [&](int lhs, int rhs) {
            return nums[lhs] < nums[rhs];
        });

        vector<int> result_arr(elem_cnt);
        int chain_start = 0;

        for (int chain_end = 0; chain_end <= elem_cnt; chain_end++) {
            if (chain_end == elem_cnt || (chain_end > chain_start && 
                nums[idx_order[chain_end]] - nums[idx_order[chain_end - 1]] > limit)) {
                
                vector<int> orig_positions(idx_order.begin() + chain_start, idx_order.begin() + chain_end);
                sort(orig_positions.begin(), orig_positions.end());

                for (int offset = 0; offset < (int)orig_positions.size(); offset++)
                    result_arr[orig_positions[offset]] = nums[idx_order[chain_start + offset]];

                chain_start = chain_end;
            }
        }

        return result_arr;
    }
};
