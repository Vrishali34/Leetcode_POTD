import java.util.PriorityQueue;

class Solution {
    public int maxDistance(String s_str, int change_limit) {
        int seq_length = s_str.length();
        int ultimate_peak_distance = 0;

        for (int axis_case = 0; axis_case < 4; axis_case++) {
            int current_horiz = 0;
            int current_vert = 0;
            
            long current_quad_sum = 0; // Use long to avoid overflow for sums
            long running_gains_total = 0;
            PriorityQueue<Integer> gain_min_heap = new PriorityQueue<>();

            for (int char_idx = 0; char_idx < seq_length; char_idx++) {
                char original_char = s_str.charAt(char_idx);
                int move_horiz = 0, move_vert = 0;

                if (original_char == 'N') move_vert = 1;
                else if (original_char == 'S') move_vert = -1;
                else if (original_char == 'E') move_horiz = 1;
                else move_horiz = -1; 

                current_horiz += move_horiz;
                current_vert += move_vert;

                int potential_bonus = 0;
                
                if (axis_case == 0) { // Maximize x + y
                    if (original_char == 'S') potential_bonus = 2; // S -> N/E (+2 to y or x)
                    else if (original_char == 'W') potential_bonus = 2; // W -> N/E (+2 to y or x)
                } else if (axis_case == 1) { // Maximize x - y
                    if (original_char == 'N') potential_bonus = 2; // N -> S/E (+2 to -y or +x)
                    else if (original_char == 'W') potential_bonus = 2; // W -> S/E (+2 to x or -y)
                } else if (axis_case == 2) { // Maximize -x + y
                    if (original_char == 'S') potential_bonus = 2; // S -> N/W (+2 to y or -x)
                    else if (original_char == 'E') potential_bonus = 2; // E -> N/W (+2 to y or -x)
                } else { // Maximize -x - y
                    if (original_char == 'N') potential_bonus = 2; // N -> S/W (+2 to -y or -x)
                    else if (original_char == 'E') potential_bonus = 2; // E -> S/W (+2 to -y or -x)
                }
                
                if (potential_bonus > 0) {
                    gain_min_heap.offer(potential_bonus);
                    running_gains_total += potential_bonus;
                }

                while (gain_min_heap.size() > change_limit) {
                    running_gains_total -= gain_min_heap.poll();
                }
                
                long current_projected_score;
                if (axis_case == 0) current_projected_score = current_horiz + current_vert;
                else if (axis_case == 1) current_projected_score = current_horiz - current_vert;
                else if (axis_case == 2) current_projected_score = -current_horiz + current_vert;
                else current_projected_score = -current_horiz - current_vert;

                ultimate_peak_distance = Math.max(ultimate_peak_distance, (int)(current_projected_score + running_gains_total));
            }
        }
        
        return ultimate_peak_distance;
    }
}
