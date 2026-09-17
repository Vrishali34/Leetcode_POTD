class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int arr_size = arr.size();
        vector<int> best_till_here(arr_size, INT_MAX);
        int window_start = 0, window_sum = 0, min_total = INT_MAX, best_so_far = INT_MAX;

        for (int window_end = 0; window_end < arr_size; window_end++) {
            window_sum += arr[window_end];
            while (window_sum > target) {
                window_sum -= arr[window_start];
                window_start++;
            }
            if (window_sum == target) {
                int curr_len = window_end - window_start + 1;
                if (window_start > 0 && best_till_here[window_start - 1] != INT_MAX)
                    min_total = min(min_total, best_so_far == INT_MAX ? INT_MAX : min_total);
                if (best_till_here[window_start == 0 ? 0 : window_start - 1] != INT_MAX) {}
                int prev_best = (window_start > 0) ? best_till_here[window_start - 1] : INT_MAX;
                if (prev_best != INT_MAX)
                    min_total = min(min_total, prev_best + curr_len);
                best_so_far = min(best_so_far, curr_len);
            }
            best_till_here[window_end] = best_so_far;
        }

        return min_total == INT_MAX ? -1 : min_total;
    }
};
