class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n_bots = robots.size();
        vector<pair<int, int>> bot_mesh(n_bots);
        for (int i = 0; i < n_bots; ++i) bot_mesh[i] = {robots[i], distance[i]};
        sort(bot_mesh.begin(), bot_mesh.end());
        sort(walls.begin(), walls.end());
        bot_mesh.push_back({(int)2e9, 0});

        auto get_sum = [&](int low, int high) {
            if (low > high) return 0;
            return (int)(upper_bound(walls.begin(), walls.end(), high) - lower_bound(walls.begin(), walls.end(), low));
        };

        vector<vector<int>> dp_matrix(n_bots, vector<int>(2));
        dp_matrix[0][0] = get_sum(bot_mesh[0].first - bot_mesh[0].second, bot_mesh[0].first);
        dp_matrix[0][1] = get_sum(bot_mesh[0].first, min(bot_mesh[1].first - 1, bot_mesh[0].first + bot_mesh[0].second));

        for (int i = 1; i < n_bots; ++i) {
            dp_matrix[i][1] = max(dp_matrix[i-1][0], dp_matrix[i-1][1]) + get_sum(bot_mesh[i].first, min(bot_mesh[i+1].first - 1, bot_mesh[i].first + bot_mesh[i].second));
            int standard_l = dp_matrix[i-1][0] + get_sum(max(bot_mesh[i].first - bot_mesh[i].second, bot_mesh[i-1].first + 1), bot_mesh[i].first);
            int start_idx = max(bot_mesh[i].first - bot_mesh[i].second, bot_mesh[i-1].first + 1);
            int end_idx = min(bot_mesh[i-1].first + bot_mesh[i-1].second, bot_mesh[i].first - 1);
            int overlap_adj = dp_matrix[i-1][1] + get_sum(start_idx, bot_mesh[i].first) - get_sum(start_idx, end_idx);
            dp_matrix[i][0] = max(standard_l, overlap_adj);
        }
        return max(dp_matrix[n_bots-1][0], dp_matrix[n_bots-1][1]);
    }
};
