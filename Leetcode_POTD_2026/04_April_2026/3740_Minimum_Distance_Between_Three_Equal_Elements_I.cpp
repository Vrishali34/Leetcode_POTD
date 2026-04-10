class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> val_pos;
        for (int i = 0; i < nums.size(); ++i) val_pos[nums[i]].push_back(i);
        int min_span = 1e9;
        for (auto& [val, pos] : val_pos) {
            if (pos.size() < 3) continue;
            for (int i = 0; i + 2 < pos.size(); ++i) 
                min_span = min(min_span, 2 * (pos[i + 2] - pos[i]));
        }
        return min_span == 1e9 ? -1 : min_span;
    }
};
