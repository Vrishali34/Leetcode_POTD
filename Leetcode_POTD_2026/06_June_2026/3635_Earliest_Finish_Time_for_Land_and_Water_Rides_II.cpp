class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        auto route_calc = [](vector<int>& start_pts, vector<int>& span_len, vector<int>& next_start, vector<int>& next_span) -> int {
            int size_a = start_pts.size(), size_b = next_start.size();
            vector<pair<int, int>> lane_a(size_a), lane_b(size_b);
            for(int i = 0; i < size_a; ++i) lane_a[i] = {start_pts[i], span_len[i]};
            for(int j = 0; j < size_b; ++j) lane_b[j] = {next_start[j], next_span[j]};
            sort(lane_a.begin(), lane_a.end());
            sort(lane_b.begin(), lane_b.end());
            
            vector<int> pre_span(size_b), suf_term(size_b);
            pre_span[0] = lane_b[0].second;
            for(int j = 1; j < size_b; ++j) pre_span[j] = min(pre_span[j - 1], lane_b[j].second);
            suf_term[size_b - 1] = lane_b[size_b - 1].first + lane_b[size_b - 1].second;
            for(int j = size_b - 2; j >= 0; --j) suf_term[j] = min(suf_term[j + 1], lane_b[j].first + lane_b[j].second);
            
            int global_min = 2e9;
            for(int i = 0; i < size_a; ++i) {
                int term_a = lane_a[i].first + lane_a[i].second;
                int low = 0, high = size_b - 1, split_idx = -1;
                while(low <= high) {
                    int mid = low + (high - low) / 2;
                    if(lane_b[mid].first <= term_a) {
                        split_idx = mid;
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
                if(split_idx != -1) global_min = min(global_min, term_a + pre_span[split_idx]);
                if(split_idx + 1 < size_b) global_min = min(global_min, suf_term[split_idx + 1]);
            }
            return global_min;
        };
        return min(route_calc(landStartTime, landDuration, waterStartTime, waterDuration), route_calc(waterStartTime, waterDuration, landStartTime, landDuration));
    }
};
