#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int maxDistance(std::string s_str, int change_limit) {
        int seq_length = s_str.length();
        long long ultimate_peak_distance = 0; // Use long long for distance to prevent overflow

        for (int axis_case = 0; axis_case < 4; ++axis_case) {
            long long current_horiz = 0;
            long long current_vert = 0;
            
            long long running_gains_total = 0;
            std::priority_queue<int, std::vector<int>, std::greater<int>> gain_min_heap; // Min-heap

            for (int char_idx = 0; char_idx < seq_length; ++char_idx) {
                char original_char = s_str[char_idx];
                int move_horiz = 0, move_vert = 0;

                if (original_char == 'N') move_vert = 1;
                else if (original_char == 'S') move_vert = -1;
                else if (original_char == 'E') move_horiz = 1;
                else move_horiz = -1; 

                current_horiz += move_horiz;
                current_vert += move_vert;

                int potential_bonus = 0;
                
                if (axis_case == 0) { // Maximize x + y
                    if (original_char == 'S') potential_bonus = 2;
                    else if (original_char == 'W') potential_bonus = 2;
                } else if (axis_case == 1) { // Maximize x - y
                    if (original_char == 'N') potential_bonus = 2;
                    else if (original_char == 'W') potential_bonus = 2;
                } else if (axis_case == 2) { // Maximize -x + y
                    if (original_char == 'S') potential_bonus = 2;
                    else if (original_char == 'E') potential_bonus = 2;
                } else { // Maximize -x - y
                    if (original_char == 'N') potential_bonus = 2;
                    else if (original_char == 'E') potential_bonus = 2;
                }
                
                if (potential_bonus > 0) {
                    gain_min_heap.push(potential_bonus);
                    running_gains_total += potential_bonus;
                }

                while (gain_min_heap.size() > change_limit) {
                    running_gains_total -= gain_min_heap.top();
                    gain_min_heap.pop();
                }
                
                long long current_projected_score;
                if (axis_case == 0) current_projected_score = current_horiz + current_vert;
                else if (axis_case == 1) current_projected_score = current_horiz - current_vert;
                else if (axis_case == 2) current_projected_score = -current_horiz + current_vert;
                else current_projected_score = -current_horiz - current_vert;

                ultimate_peak_distance = std::max(ultimate_peak_distance, current_projected_score + running_gains_total);
            }
        }
        
        return static_cast<int>(ultimate_peak_distance);
    }
};
