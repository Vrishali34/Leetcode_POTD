class Solution {
public:
    int findMin(vector<int>& rotated_elements) {
        int rotation_start_pos = 0;
        int rotation_end_pos = rotated_elements.size() - 1;
        while (rotation_start_pos < rotation_end_pos) {
            int element_midpoint_idx = rotation_start_pos + (rotation_end_pos - rotation_start_pos) / 2;
            if (rotated_elements[element_midpoint_idx] > rotated_elements[rotation_end_pos]) {
                rotation_start_pos = element_midpoint_idx + 1;
            } else if (rotated_elements[element_midpoint_idx] < rotated_elements[rotation_end_pos]) {
                rotation_end_pos = element_midpoint_idx;
            } else {
                rotation_end_pos--;
            }
        }
        return rotated_elements[rotation_start_pos];
    }
};
