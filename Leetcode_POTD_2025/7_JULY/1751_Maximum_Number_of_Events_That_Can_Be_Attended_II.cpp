class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const auto& l_e, const auto& r_e){
            return l_e[1] < r_e[1];
        });

        int num_events = events.size();
        vector<vector<int>> dp_table(num_events + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= num_events; ++i) {
            int current_start_day = events[i-1][0];
            int current_value = events[i-1][2];

            // Find the latest non-overlapping event using binary search
            // We need to find an event `p` such that events[p][1] < current_start_day
            // Since events are sorted by end_day, we can use binary search on indices
            int prev_event_idx = 0;
            int low_boundary = 0, high_boundary = i - 2; // Search in events before current
            while (low_boundary <= high_boundary) {
                int mid_point = low_boundary + (high_boundary - low_boundary) / 2;
                if (events[mid_point][1] < current_start_day) {
                    prev_event_idx = mid_point + 1; // potential candidate, try for a later one
                    low_boundary = mid_point + 1;
                } else {
                    high_boundary = mid_point - 1; // this event overlaps or is too late
                }
            }

            for (int j = 1; j <= k; ++j) {
                dp_table[i][j] = max(dp_table[i-1][j], dp_table[prev_event_idx][j-1] + current_value);
            }
        }
        return dp_table[num_events][k];
    }
};
