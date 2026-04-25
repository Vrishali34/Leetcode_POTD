class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        auto map_to_linear = [&](int x, int y) {
            if (y == 0) return (long long)x;
            if (x == side) return (long long)side + y;
            if (y == side) return (long long)2 * side + (side - x);
            return (long long)3 * side + (side - y);
        };

        vector<pair<long long, pair<int, int>>> vertex_registry;
        for (auto& p : points) vertex_registry.push_back({map_to_linear(p[0], p[1]), {p[0], p[1]}});
        sort(vertex_registry.begin(), vertex_registry.end());

        int total_nodes = vertex_registry.size();
        auto validate_gap = [&](int min_step) {
            vector<int> leap_target(2 * total_nodes);
            int right_ptr = 0;
            for (int left_ptr = 0; left_ptr < 2 * total_nodes; ++left_ptr) {
                right_ptr = max(right_ptr, left_ptr + 1);
                while (right_ptr < 2 * total_nodes) {
                    auto& p1 = vertex_registry[left_ptr % total_nodes].second;
                    auto& p2 = vertex_registry[right_ptr % total_nodes].second;
                    if (abs(p1.first - p2.first) + abs(p1.second - p2.second) >= min_step) break;
                    right_ptr++;
                }
                leap_target[left_ptr] = right_ptr;
            }

            for (int start_pos = 0; start_pos < total_nodes; ++start_pos) {
                int current_pos = start_pos;
                for (int count = 0; count < k; ++count) {
                    if (current_pos >= 2 * total_nodes) break;
                    current_pos = leap_target[current_pos];
                }
                if (current_pos <= start_pos + total_nodes) return true;
                if (leap_target[start_pos] == start_pos + 1 && total_nodes > 1000) {
                    int min_jump = 1e9;
                    for(int i=0; i<total_nodes; ++i) min_jump = min(min_jump, leap_target[i]-i);
                    if (min_jump > total_nodes/k) return false;
                }
            }
            return false;
        };

        int low_bound = 1, high_bound = 2 * side, best_dist = 0;
        while (low_bound <= high_bound) {
            int mid_dist = low_bound + (high_bound - low_bound) / 2;
            if (validate_gap(mid_dist)) {
                best_dist = mid_dist;
                low_bound = mid_dist + 1;
            } else {
                high_bound = mid_dist - 1;
            }
        }
        return best_dist;
    }
};
