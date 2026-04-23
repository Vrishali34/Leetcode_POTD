class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n_size = nums.size();
        vector<long long> dist_sums(n_size, 0);
        unordered_map<int, vector<int>> num_to_idxs;
        for (int i = 0; i < n_size; ++i) num_to_idxs[nums[i]].push_back(i);
        for (auto& [val, idx_list] : num_to_idxs) {
            long long list_sz = idx_list.size(), left_sum = 0, right_sum = 0;
            for (int index : idx_list) right_sum += index;
            for (int i = 0; i < list_sz; ++i) {
                long long cur_idx = idx_list[i];
                right_sum -= cur_idx;
                dist_sums[cur_idx] = (cur_idx * i - left_sum) + (right_sum - cur_idx * (list_sz - 1 - i));
                left_sum += cur_idx;
            }
        }
        return dist_sums;
    }
};
