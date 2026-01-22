class Solution {
public:
    int minimumPairRemoval(vector<int>& val_arr) {
        int merge_count = 0;
        while (true) {
            bool is_sorted = true;
            for (int i = 1; i < val_arr.size(); ++i) {
                if (val_arr[i-1] > val_arr[i]) { is_sorted = false; break; }
            }
            if (is_sorted) return merge_count;

            int best_idx = 0;
            long long min_pair_sum = (long long)val_arr[0] + val_arr[1];
            for (int i = 1; i < (int)val_arr.size() - 1; ++i) {
                long long cur_sum = (long long)val_arr[i] + val_arr[i+1];
                if (cur_sum < min_pair_sum) { min_pair_sum = cur_sum; best_idx = i; }
            }
            val_arr[best_idx] += val_arr[best_idx + 1];
            val_arr.erase(val_arr.begin() + best_idx + 1);
            merge_count++;
        }
    }
};
