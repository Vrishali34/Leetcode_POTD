class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int max_r = grid.size(), max_c = grid[0].size();
        vector<vector<int>> remaining_hp(max_r, vector<int>(max_c, -1));
        deque<pair<int, int>> walk_q;
        
        remaining_hp[0][0] = health - grid[0][0];
        if (remaining_hp[0][0] <= 0) return false;
        walk_q.push_front({0, 0});
        
        int r_shifts[] = {-1, 1, 0, 0};
        int c_shifts[] = {0, 0, -1, 1};
        
        while (!walk_q.empty()) {
            auto [curr_r, curr_c] = walk_q.front();
            walk_q.pop_front();
            
            if (curr_r == max_r - 1 && curr_c == max_c - 1) {
                return remaining_hp[curr_r][curr_c] >= 1;
            }
            
            for (int i = 0; i < 4; ++i) {
                int next_r = curr_r + r_shifts[i];
                int next_c = curr_c + c_shifts[i];
                
                if (next_r >= 0 && next_r < max_r && next_c >= 0 && next_c < max_c) {
                    int next_hp = remaining_hp[curr_r][curr_c] - grid[next_r][next_c];
                    if (next_hp > remaining_hp[next_r][next_c]) {
                        remaining_hp[next_r][next_c] = next_hp;
                        if (grid[next_r][next_c] == 0) {
                            walk_q.push_front({next_r, next_c});
                        } else {
                            walk_q.push_back({next_r, next_c});
                        }
                    }
                }
            }
        }
        return false;
    }
};
