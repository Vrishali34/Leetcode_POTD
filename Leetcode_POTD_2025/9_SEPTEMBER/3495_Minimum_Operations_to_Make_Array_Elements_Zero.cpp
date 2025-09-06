class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total_actions = 0;
        for (const auto& query_range : queries) {
            long long low_val = query_range[0], high_val = query_range[1];
            long long low_ops_needed = floor(log(low_val) / log(4)) + 1;
            long long high_ops_needed = floor(log(high_val) / log(4)) + 1;
            long long total_div_counts = 0;
            for (long long k = low_ops_needed; k <= high_ops_needed; ++k) {
                long long start = max(low_val, (long long)pow(4, k - 1));
                long long end = min(high_val, (long long)pow(4, k) - 1);
                if (start <= end) {
                    total_div_counts += (end - start + 1) * k;
                }
            }
            total_actions += (total_div_counts + 1) / 2;
        }
        return total_actions;
    }
};
