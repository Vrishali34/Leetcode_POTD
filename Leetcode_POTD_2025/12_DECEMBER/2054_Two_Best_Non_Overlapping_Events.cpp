class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n_len = events.size();
        sort(events.begin(), events.end());
        vector<int> max_val_suffix(n_len);
        max_val_suffix[n_len - 1] = events[n_len - 1][2];
        for (int i = n_len - 2; i >= 0; --i) 
            max_val_suffix[i] = max(events[i][2], max_val_suffix[i + 1]);
        int peak_sum = 0;
        for (int i = 0; i < n_len; ++i) {
            int current_val = events[i][2];
            auto next_ptr = upper_bound(events.begin() + i + 1, events.end(), vector<int>{events[i][1], (int)2e9, (int)2e9});
            if (next_ptr != events.end()) {
                int idx = distance(events.begin(), next_ptr);
                current_val += max_val_suffix[idx];
            }
            peak_sum = max(peak_sum, current_val);
        }
        return peak_sum;
    }
};
