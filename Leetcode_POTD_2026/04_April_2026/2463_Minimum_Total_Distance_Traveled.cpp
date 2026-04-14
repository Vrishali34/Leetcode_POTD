class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int robot_count = robot.size(), facility_count = factory.size();
        vector<vector<long long>> path_cost(facility_count + 1, vector<long long>(robot_count + 1, 1e15));
        for (int i = 0; i <= facility_count; ++i) path_cost[i][0] = 0;
        for (int j = 1; j <= facility_count; ++j) {
            for (int i = 1; i <= robot_count; ++i) {
                path_cost[j][i] = path_cost[j - 1][i];
                long long current_tally = 0;
                for (int k = 1; k <= factory[j - 1][1] && i - k >= 0; ++k) {
                    current_tally += abs(robot[i - k] - factory[j - 1][0]);
                    path_cost[j][i] = min(path_cost[j][i], path_cost[j - 1][i - k] + current_tally);
                }
            }
        }
        return path_cost[facility_count][robot_count];
    }
};
