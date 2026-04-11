class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> val_indices;
        int min_span = INT_MAX;
        for (int idx = 0; idx < nums.size(); ++idx) {
            val_indices[nums[idx]].push_back(idx);
        }
        for (auto& [val, pos_list] : val_indices) {
            if (pos_list.size() < 3) continue;
            for (int i = 2; i < pos_list.size(); ++i) {
                min_span = min(min_span, 2 * (pos_list[i] - pos_list[i - 2]));
            }
        }
        return min_span == INT_MAX ? -1 : min_span;
    }
};
