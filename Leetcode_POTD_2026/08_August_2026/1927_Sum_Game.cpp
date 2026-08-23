class Solution {
public:
    bool sumGame(string num) {
        int len_total = num.size(), half_len = len_total / 2;
        int sum_left = 0, sum_right = 0, quest_left = 0, quest_right = 0;

        for (int idx = 0; idx < half_len; idx++) {
            if (num[idx] == '?') quest_left++;
            else sum_left += num[idx] - '0';
        }
        for (int idx = half_len; idx < len_total; idx++) {
            if (num[idx] == '?') quest_right++;
            else sum_right += num[idx] - '0';
        }

        int quest_total = quest_left + quest_right;
        if (quest_total % 2 == 1) return true;

        int diff_val = sum_left - sum_right;
        diff_val += 9 * (quest_left - quest_right) / 2;
        return diff_val != 0;
    }
};
