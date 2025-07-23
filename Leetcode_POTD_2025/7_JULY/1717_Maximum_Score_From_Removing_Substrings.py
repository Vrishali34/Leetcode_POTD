class Solution(object):
    def maximumGain(self, s, x, y):
        """
        :type s: str
        :type x: int
        :type y: int
        :rtype: int
        """
        total_points = 0
        
        # Determine which pair to prioritize
        if x >= y:
            first_pair = "ab"
            first_gain = x
            second_pair = "ba"
            second_gain = y
        else:
            first_pair = "ba"
            first_gain = y
            second_pair = "ab"
            second_gain = x
            
        # First pass for the higher-scoring pair
        temp_list = []
        for char_s in s:
            if temp_list and temp_list[-1] == first_pair[0] and char_s == first_pair[1]:
                total_points += first_gain
                temp_list.pop()
            else:
                temp_list.append(char_s)
        
        # Second pass for the lower-scoring pair on the remaining string
        remaining_s = "".join(temp_list)
        temp_list = []
        for char_s in remaining_s:
            if temp_list and temp_list[-1] == second_pair[0] and char_s == second_pair[1]:
                total_points += second_gain
                temp_list.pop()
            else:
                temp_list.append(char_s)
                
        return total_points
