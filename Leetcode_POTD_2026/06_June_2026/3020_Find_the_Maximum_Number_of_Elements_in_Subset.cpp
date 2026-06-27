class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> tally_map;
        for (int val : nums) {
            tally_map[val]++;
        }
        int max_len = 1;
        if (tally_map.count(1)) {
            int ones_cnt = tally_map[1];
            max_len = ones_cnt % 2 == 0 ? ones_cnt - 1 : ones_cnt;
        }
        for (auto& [base_val, freq] : tally_map) {
            if (base_val == 1) continue;
            int current_len = 0;
            long long active_num = base_val;
            while (tally_map.count(active_num) && tally_map[active_num] >= 2) {
                current_len += 2;
                active_num *= active_num;
            }
            if (tally_map.count(active_num)) {
                current_len += 1;
            } else {
                current_len -= 1;
            }
            max_len = max(max_len, current_len);
        }
        return max_len;
    }
};
