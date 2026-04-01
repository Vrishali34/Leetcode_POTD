class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int robot_count = positions.size();
        vector<int> robot_indices(robot_count);
        iota(robot_indices.begin(), robot_indices.end(), 0);
        
        sort(robot_indices.begin(), robot_indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> active_stack;
        for (int idx : robot_indices) {
            if (directions[idx] == 'R') {
                active_stack.push_back(idx);
            } else {
                while (!active_stack.empty() && healths[idx] > 0) {
                    int top_idx = active_stack.back();
                    if (healths[idx] > healths[top_idx]) {
                        healths[idx] -= 1;
                        healths[top_idx] = 0;
                        active_stack.pop_back();
                    } else if (healths[idx] < healths[top_idx]) {
                        healths[top_idx] -= 1;
                        healths[idx] = 0;
                    } else {
                        healths[idx] = 0;
                        healths[top_idx] = 0;
                        active_stack.pop_back();
                    }
                }
            }
        }

        vector<int> survivors;
        for (int h : healths) if (h > 0) survivors.push_back(h);
        return survivors;
    }
};
