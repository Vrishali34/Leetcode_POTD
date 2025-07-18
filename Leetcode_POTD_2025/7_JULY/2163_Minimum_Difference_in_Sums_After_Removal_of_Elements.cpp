class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int temporal_n = nums.size() / 3;
        vector<long long> bygone_min_sums(nums.size());
        priority_queue<int> vault_min_heap;
        long long current_vault_sum = 0;

        for (int i = 0; i < 2 * temporal_n; ++i) {
            vault_min_heap.push(nums[i]);
            current_vault_sum += nums[i];
            if (vault_min_heap.size() > temporal_n) {
                current_vault_sum -= vault_min_heap.top();
                vault_min_heap.pop();
            }
            if (vault_min_heap.size() == temporal_n) {
                bygone_min_sums[i] = current_vault_sum;
            }
        }

        vector<long long> future_max_sums(nums.size());
        priority_queue<int, vector<int>, greater<int>> abyss_max_heap;
        long long current_abyss_sum = 0;

        for (int i = nums.size() - 1; i >= temporal_n; --i) {
            abyss_max_heap.push(nums[i]);
            current_abyss_sum += nums[i];
            if (abyss_max_heap.size() > temporal_n) {
                current_abyss_sum -= abyss_max_heap.top();
                abyss_max_heap.pop();
            }
            if (abyss_max_heap.size() == temporal_n) {
                future_max_sums[i] = current_abyss_sum;
            }
        }

        long long cosmic_delta = LLONG_MAX;

        for (int k = temporal_n - 1; k < 2 * temporal_n; ++k) {
            if (bygone_min_sums[k] != 0 && future_max_sums[k + 1] != 0) {
                cosmic_delta = min(cosmic_delta, bygone_min_sums[k] - future_max_sums[k + 1]);
            }
        }
        return cosmic_delta;
    }
};
