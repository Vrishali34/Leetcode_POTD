class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s_val, vector<vector<int>>& query_list) {
        int seq_length = s_val.size();
        int base_active_count = 0;
        for (char ch_val : s_val) if (ch_val == '1') base_active_count++;

        vector<int> null_seg_lengths, null_seg_lefts, null_seg_rights;
        for (int scan_ptr = 0; scan_ptr < seq_length;) {
            int seg_origin = scan_ptr;
            while (scan_ptr < seq_length && s_val[scan_ptr] == s_val[seg_origin]) scan_ptr++;
            if (s_val[seg_origin] == '0') {
                null_seg_lengths.push_back(scan_ptr - seg_origin);
                null_seg_lefts.push_back(seg_origin);
                null_seg_rights.push_back(scan_ptr - 1);
            }
        }

        int total_null_segs = null_seg_lengths.size();
        if (total_null_segs < 2) return vector<int>(query_list.size(), base_active_count);

        vector<int> consecutive_sum_arr(total_null_segs - 1);
        for (int idx = 0; idx < total_null_segs - 1; ++idx) {
            consecutive_sum_arr[idx] = null_seg_lengths[idx] + null_seg_lengths[idx + 1];
        }

        int arr_capacity = consecutive_sum_arr.size();
        vector<vector<int>> rmq_grid(18, vector<int>(arr_capacity));
        rmq_grid[0] = consecutive_sum_arr;

        for (int level = 1; (1 << level) <= arr_capacity; ++level) {
            for (int pos = 0; pos + (1 << level) <= arr_capacity; ++pos) {
                rmq_grid[level][pos] = max(rmq_grid[level - 1][pos], rmq_grid[level - 1][pos + (1 << (level - 1))]);
            }
        }

        vector<int> final_answers;
        final_answers.reserve(query_list.size());

        for (const auto& curr_sub_range : query_list) {
            int range_start = curr_sub_range[0], range_end = curr_sub_range[1];
            int left_seg_pos = lower_bound(null_seg_rights.begin(), null_seg_rights.end(), range_start) - null_seg_rights.begin();
            int right_seg_pos = upper_bound(null_seg_lefts.begin(), null_seg_lefts.end(), range_end) - null_seg_lefts.begin() - 1;

            if (left_seg_pos >= total_null_segs || right_seg_pos < 0 || left_seg_pos >= right_seg_pos) {
                final_answers.push_back(base_active_count);
                continue;
            }

            int bounded_first_len = null_seg_rights[left_seg_pos] - max(null_seg_lefts[left_seg_pos], range_start) + 1;
            int bounded_last_len = min(null_seg_rights[right_seg_pos], range_end) - null_seg_lefts[right_seg_pos] + 1;

            if (left_seg_pos + 1 == right_seg_pos) {
                final_answers.push_back(base_active_count + bounded_first_len + bounded_last_len);
                continue;
            }

            int candidate_opt1 = bounded_first_len + null_seg_lengths[left_seg_pos + 1];
            int candidate_opt2 = null_seg_lengths[right_seg_pos - 1] + bounded_last_len;
            
            int candidate_opt3 = 0;
            int query_a = left_seg_pos + 1, query_b = right_seg_pos - 2;
            if (query_a <= query_b) {
                int dist_len = query_b - query_a + 1;
                int log_shift = 31 - __builtin_clz(dist_len);
                candidate_opt3 = max(rmq_grid[log_shift][query_a], rmq_grid[log_shift][query_b - (1 << log_shift) + 1]);
            }

            final_answers.push_back(base_active_count + max({candidate_opt1, candidate_opt2, candidate_opt3}));
        }

        return final_answers;
    }
};
