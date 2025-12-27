class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> idle_slots;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> active_hub;
        vector<int> tally_log(n, 0);
        for (int i = 0; i < n; ++i) idle_slots.push(i);
        for (auto& session : meetings) {
            long long start_mark = session[0], end_mark = session[1];
            while (!active_hub.empty() && active_hub.top().first <= start_mark) {
                idle_slots.push(active_hub.top().second);
                active_hub.pop();
            }
            if (!idle_slots.empty()) {
                int pick = idle_slots.top();
                idle_slots.pop();
                tally_log[pick]++;
                active_hub.push({end_mark, pick});
            } else {
                auto [finish_time, room_id] = active_hub.top();
                active_hub.pop();
                tally_log[room_id]++;
                active_hub.push({finish_time + (end_mark - start_mark), room_id});
            }
        }
        return max_element(tally_log.begin(), tally_log.end()) - tally_log.begin();
    }
};
