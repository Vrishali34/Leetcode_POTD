class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int sequence_length = nums.size();
        int tree_capacity = 1;
        while (tree_capacity < sequence_length) tree_capacity *= 2;
        
        vector<int> upper_bound_tree(2 * tree_capacity, 0);
        vector<int> lower_bound_tree(2 * tree_capacity, 1e9 + 7);
        
        for (int index = 0; index < sequence_length; ++index) {
            upper_bound_tree[tree_capacity + index] = nums[index];
            lower_bound_tree[tree_capacity + index] = nums[index];
        }
        for (int node = tree_capacity - 1; node > 0; --node) {
            upper_bound_tree[node] = max(upper_bound_tree[2 * node], upper_bound_tree[2 * node + 1]);
            lower_bound_tree[node] = min(lower_bound_tree[2 * node], lower_bound_tree[2 * node + 1]);
        }
        
        auto compute_range_spread = [&](int left_bound, int right_bound) {
            left_bound += tree_capacity;
            right_bound += tree_capacity;
            int current_peak = 0, current_trough = 1e9 + 7;
            while (left_bound <= right_bound) {
                if (left_bound % 2 == 1) {
                    current_peak = max(current_peak, upper_bound_tree[left_bound]);
                    current_trough = min(current_trough, lower_bound_tree[left_bound]);
                    left_bound++;
                }
                if (right_bound % 2 == 0) {
                    current_peak = max(current_peak, upper_bound_tree[right_bound]);
                    current_trough = min(current_trough, lower_bound_tree[right_bound]);
                    right_bound--;
                }
                left_bound /= 2;
                right_bound /= 2;
            }
            return current_peak - current_trough;
        };
        
        priority_queue<tuple<int, int, int>> maximum_span_heap;
        for (int start_point = 0; start_point < sequence_length; ++start_point) {
            maximum_span_heap.push({compute_range_spread(start_point, sequence_length - 1), start_point, sequence_length - 1});
        }
        
        long long accumulated_score = 0;
        while (k-- > 0 && !maximum_span_heap.empty()) {
            auto [span_weight, segment_start, segment_end] = maximum_span_heap.top();
            maximum_span_heap.pop();
            accumulated_score += span_weight;
            if (segment_end > segment_start) {
                maximum_span_heap.push({compute_range_spread(segment_start, segment_end - 1), segment_start, segment_end - 1});
            }
        }
        return accumulated_score;
    }
};
