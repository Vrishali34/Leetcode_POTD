class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int stone_count = stones.size();
        vector<int> prefix_sum(stone_count);
        prefix_sum[0] = stones[0];
        for (int idx = 1; idx < stone_count; idx++)
            prefix_sum[idx] = prefix_sum[idx - 1] + stones[idx];

        int best_diff = prefix_sum[stone_count - 1];
        for (int cut_idx = stone_count - 2; cut_idx >= 1; cut_idx--)
            best_diff = max(best_diff, prefix_sum[cut_idx] - best_diff);

        return best_diff;
    }
};
