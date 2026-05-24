class Solution {
public:
    int maxJumps(vector<int>& heights_list, int max_step) {
        int total_elements = heights_list.size();
        vector<int> max_paths(total_elements, -1);
        
        auto evaluate_index = [&](auto& self, int current_idx) -> int {
            if (max_paths[current_idx] != -1) return max_paths[current_idx];
            int supreme_path = 1;
            
            for (int offset = 1; offset <= max_step && current_idx + offset < total_elements; ++offset) {
                if (heights_list[current_idx + offset] >= heights_list[current_idx]) break;
                supreme_path = max(supreme_path, 1 + self(self, current_idx + offset));
            }
            for (int offset = 1; offset <= max_step && current_idx - offset >= 0; ++offset) {
                if (heights_list[current_idx - offset] >= heights_list[current_idx]) break;
                supreme_path = max(supreme_path, 1 + self(self, current_idx - offset));
            }
            return max_paths[current_idx] = supreme_path;
        };
        
        int absolute_max_jumps = 0;
        for (int initial_idx = 0; initial_idx < total_elements; ++initial_idx) {
            absolute_max_jumps = max(absolute_max_jumps, evaluate_index(evaluate_index, initial_idx));
        }
        return absolute_max_jumps;
    }
};
