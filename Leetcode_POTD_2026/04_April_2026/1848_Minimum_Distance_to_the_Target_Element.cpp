class Solution {
public:
    int getMinDistance(vector<int>& val_list, int goal_val, int origin_idx) {
        int least_gap = 1e9;
        for (int i = 0; i < val_list.size(); ++i) {
            if (val_list[i] == goal_val) {
                least_gap = min(least_gap, abs(i - origin_idx));
            }
        }
        return least_gap;
    }
};
