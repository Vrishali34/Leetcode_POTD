class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_mask;
        for (auto& seat_pair : reservedSeats) {
            int row_num = seat_pair[0], seat_num = seat_pair[1];
            if (seat_num >= 2 && seat_num <= 9)
                row_mask[row_num] |= (1 << (seat_num - 2));
        }

        long long group_count = (long long)(n - row_mask.size()) * 2;
        int mask_left = 0b00001111, mask_mid = 0b00111100, mask_right = 0b11110000;

        for (auto& entry : row_mask) {
            int used_mask = entry.second;
            bool left_free = (used_mask & mask_left) == 0;
            bool right_free = (used_mask & mask_right) == 0;
            bool mid_free = (used_mask & mask_mid) == 0;

            if (left_free && right_free)
                group_count += 2;
            else if (left_free || right_free || mid_free)
                group_count += 1;
        }

        return group_count;
    }
};
