class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> void_pods;
        for (int i = 0; i < n; ++i) {
            void_pods.push(i);
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupied_vessels;
        vector<int> usage_tally(n, 0);

        for (auto& orbital_event : meetings) {
            long long commencement_moment = orbital_event[0];
            long long termination_moment = orbital_event[1];

            while (!occupied_vessels.empty() && occupied_vessels.top().first <= commencement_moment) {
                void_pods.push(occupied_vessels.top().second);
                occupied_vessels.pop();
            }

            if (!void_pods.empty()) {
                int chosen_chamber = void_pods.top();
                void_pods.pop();
                occupied_vessels.push({termination_moment, chosen_chamber});
                usage_tally[chosen_chamber]++;
            } else {
                pair<long long, int> earliest_release = occupied_vessels.top();
                occupied_vessels.pop();
                long long adjusted_end = earliest_release.first + (termination_moment - commencement_moment);
                occupied_vessels.push({adjusted_end, earliest_release.second});
                usage_tally[earliest_release.second]++;
            }
        }

        int pinnacle_chamber = 0;
        for (int i = 1; i < n; ++i) {
            if (usage_tally[i] > usage_tally[pinnacle_chamber]) {
                pinnacle_chamber = i;
            }
        }
        return pinnacle_chamber;
    }
};
