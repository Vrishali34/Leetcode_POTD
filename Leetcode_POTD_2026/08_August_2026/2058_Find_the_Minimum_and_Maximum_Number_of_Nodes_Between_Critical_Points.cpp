class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first_pos = -1, prev_pos = -1, cur_pos = 0;
        int min_gap = INT_MAX;
        ListNode *prev_node = head, *cur_node = head->next;
        cur_pos = 1;

        while (cur_node->next) {
            int left_val = prev_node->val, mid_val = cur_node->val, right_val = cur_node->next->val;
            bool is_peak = (mid_val > left_val && mid_val > right_val);
            bool is_valley = (mid_val < left_val && mid_val < right_val);

            if (is_peak || is_valley) {
                if (first_pos == -1) first_pos = cur_pos;
                if (prev_pos != -1) min_gap = min(min_gap, cur_pos - prev_pos);
                prev_pos = cur_pos;
            }

            prev_node = cur_node;
            cur_node = cur_node->next;
            cur_pos++;
        }

        if (prev_pos == first_pos) return {-1, -1};
        return {min_gap, prev_pos - first_pos};
    }
};
