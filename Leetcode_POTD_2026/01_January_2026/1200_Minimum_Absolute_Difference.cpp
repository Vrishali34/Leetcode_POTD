class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& num_pool) {
        sort(num_pool.begin(), num_pool.end());
        int least_gap = 2e6;
        vector<vector<int>> pair_set;
        for (int i = 0; i < num_pool.size() - 1; ++i) {
            int current_gap = num_pool[i + 1] - num_pool[i];
            if (current_gap < least_gap) {
                least_gap = current_gap;
                pair_set = {{num_pool[i], num_pool[i + 1]}};
            } else if (current_gap == least_gap) {
                pair_set.push_back({num_pool[i], num_pool[i + 1]});
            }
        }
        return pair_set;
    }
};
