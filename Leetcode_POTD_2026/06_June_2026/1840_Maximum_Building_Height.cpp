class Solution {
public:
    int maxBuilding(int total_blocks, vector<vector<int>>& height_limits) {
        if (height_limits.empty()) return total_blocks - 1;
        sort(height_limits.begin(), height_limits.end());
        int anchor_idx = 1, floor_h = 0;
        for (auto& rule_node : height_limits) {
            rule_node[1] = min(rule_node[1], rule_node[0] - anchor_idx + floor_h);
            anchor_idx = rule_node[0];
            floor_h = rule_node[1];
        }
        for (int i = height_limits.size() - 2; i >= 0; --i) {
            height_limits[i][1] = min(height_limits[i][1], height_limits[i + 1][1] + height_limits[i + 1][0] - height_limits[i][0]);
        }
        int peak_limit = total_blocks - height_limits.back()[0] + height_limits.back()[1];
        anchor_idx = 1;
        floor_h = 0;
        for (const auto& rule_node : height_limits) {
            int gap_steps = rule_node[0] - anchor_idx - abs(rule_node[1] - floor_h);
            peak_limit = max(peak_limit, max(rule_node[1], floor_h) + gap_steps / 2);
            anchor_idx = rule_node[0];
            floor_h = rule_node[1];
        }
        return peak_limit;
    }
};
