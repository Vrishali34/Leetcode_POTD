class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int total_cnt = nums.size();
        vector<int> idx_order(total_cnt);
        for (int pos = 0; pos < total_cnt; pos++) idx_order[pos] = pos;

        auto digit_sum = [](int val) {
            int sum_val = 0;
            while (val) { sum_val += val % 10; val /= 10; }
            return sum_val;
        };

        sort(idx_order.begin(), idx_order.end(), [&](int pos_a, int pos_b) {
            int sum_a = digit_sum(nums[pos_a]), sum_b = digit_sum(nums[pos_b]);
            if (sum_a != sum_b) return sum_a < sum_b;
            return nums[pos_a] < nums[pos_b];
        });

        vector<bool> visited(total_cnt, false);
        int cycle_cnt = 0;

        for (int start_pos = 0; start_pos < total_cnt; start_pos++) {
            if (visited[start_pos] || idx_order[start_pos] == start_pos) {
                if (!visited[start_pos]) cycle_cnt++;
                visited[start_pos] = true;
                continue;
            }
            int cur_pos = start_pos;
            while (!visited[cur_pos]) {
                visited[cur_pos] = true;
                cur_pos = idx_order[cur_pos];
            }
            cycle_cnt++;
        }

        return total_cnt - cycle_cnt;
    }
};
