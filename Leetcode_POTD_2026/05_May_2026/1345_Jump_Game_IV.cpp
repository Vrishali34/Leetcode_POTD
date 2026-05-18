class Solution {
public:
    int minJumps(vector<int>& arr) {
        int track_bound = arr.size();
        if (track_bound <= 1) return 0;

        unordered_map<int, vector<int>> value_clusters;
        for (int cell_idx = 0; cell_idx < track_bound; ++cell_idx) {
            value_clusters[arr[cell_idx]].push_back(cell_idx);
        }

        queue<int> horizon_nodes;
        vector<bool> trace_logged(track_bound, false);

        horizon_nodes.push(0);
        trace_logged[0] = true;
        int hop_metric = 0;

        while (!horizon_nodes.empty()) {
            int wave_breadth = horizon_nodes.size();
            for (int step = 0; step < wave_breadth; ++step) {
                int spot_idx = horizon_nodes.front();
                horizon_nodes.pop();

                if (spot_idx == track_bound - 1) return hop_metric;

                if (spot_idx - 1 >= 0 && !trace_logged[spot_idx - 1]) {
                    trace_logged[spot_idx - 1] = true;
                    horizon_nodes.push(spot_idx - 1);
                }
                if (spot_idx + 1 < track_bound && !trace_logged[spot_idx + 1]) {
                    trace_logged[spot_idx + 1] = true;
                    horizon_nodes.push(spot_idx + 1);
                }

                int current_magnitude = arr[spot_idx];
                if (value_clusters.count(current_magnitude)) {
                    for (int matched_post : value_clusters[current_magnitude]) {
                        if (!trace_logged[matched_post]) {
                            trace_logged[matched_post] = true;
                            horizon_nodes.push(matched_post);
                        }
                    }
                    value_clusters.erase(current_magnitude);
                }
            }
            ++hop_metric;
        }
        return -1;
    }
};
