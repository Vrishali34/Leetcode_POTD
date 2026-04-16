class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n_len = nums.size();
        unordered_map<int, vector<int>> pos_map;
        for (int i = 0; i < n_len; ++i) pos_map[nums[i]].push_back(i);
        
        vector<int> res_vec;
        for (int q_idx : queries) {
            auto& p_list = pos_map[nums[q_idx]];
            if (p_list.size() < 2) {
                res_vec.push_back(-1);
                continue;
            }
            auto it = lower_bound(p_list.begin(), p_list.end(), q_idx);
            int idx = distance(p_list.begin(), it);
            int prev = p_list[(idx - 1 + p_list.size()) % p_list.size()];
            int next = p_list[(idx + 1) % p_list.size()];
            
            int d1 = abs(q_idx - prev);
            int d2 = abs(q_idx - next);
            res_vec.push_back(min({d1, n_len - d1, d2, n_len - d2}));
        }
        return res_vec;
    }
};
