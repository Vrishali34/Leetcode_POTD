import heapq

class Solution(object):
    def maxDistance(self, s_str, change_limit):
        """
        :type s_str: str
        :type change_limit: int
        :rtype: int
        """
        seq_length = len(s_str)
        ultimate_peak_distance = 0

        for axis_case in range(4):
            current_horiz = 0
            current_vert = 0
            
            running_gains_total = 0
            gain_min_heap = [] # Min-heap in Python

            for char_idx in range(seq_length):
                original_char = s_str[char_idx]
                move_horiz = 0
                move_vert = 0

                if original_char == 'N':
                    move_vert = 1
                elif original_char == 'S':
                    move_vert = -1
                elif original_char == 'E':
                    move_horiz = 1
                else: # original_char == 'W'
                    move_horiz = -1

                current_horiz += move_horiz
                current_vert += move_vert

                potential_bonus = 0
                
                if axis_case == 0: # Maximize x + y
                    if original_char == 'S' or original_char == 'W':
                        potential_bonus = 2
                elif axis_case == 1: # Maximize x - y
                    if original_char == 'N' or original_char == 'W':
                        potential_bonus = 2
                elif axis_case == 2: # Maximize -x + y
                    if original_char == 'S' or original_char == 'E':
                        potential_bonus = 2
                else: # axis_case == 3, Maximize -x - y
                    if original_char == 'N' or original_char == 'E':
                        potential_bonus = 2
                
                if potential_bonus > 0:
                    heapq.heappush(gain_min_heap, potential_bonus)
                    running_gains_total += potential_bonus

                while len(gain_min_heap) > change_limit:
                    running_gains_total -= heapq.heappop(gain_min_heap)
                
                current_projected_score = 0
                if axis_case == 0:
                    current_projected_score = current_horiz + current_vert
                elif axis_case == 1:
                    current_projected_score = current_horiz - current_vert
                elif axis_case == 2:
                    current_projected_score = -current_horiz + current_vert
                else: # axis_case == 3
                    current_projected_score = -current_horiz - current_vert

                ultimate_peak_distance = max(ultimate_peak_distance, current_projected_score + running_gains_total)
        
        return ultimate_peak_distance
