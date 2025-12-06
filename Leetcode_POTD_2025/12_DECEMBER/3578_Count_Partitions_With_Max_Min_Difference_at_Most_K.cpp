class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int num_len = nums.size();
        int modulo = 1e9 + 7;
        vector<int> combinations(num_len + 1, 0);
        vector<int> acc_sum(num_len + 1, 0);
        deque<int> min_d, max_d;
        
        combinations[0] = 1;
        acc_sum[0] = 1;
        int cursor = 0;

        for (int iter = 0; iter < num_len; ++iter) {
            while (!min_d.empty() && nums[min_d.back()] >= nums[iter]) min_d.pop_back();
            while (!max_d.empty() && nums[max_d.back()] <= nums[iter]) max_d.pop_back();
            min_d.push_back(iter);
            max_d.push_back(iter);

            while (nums[max_d.front()] - nums[min_d.front()] > k) {
                cursor++;
                if (min_d.front() < cursor) min_d.pop_front();
                if (max_d.front() < cursor) max_d.pop_front();
            }

            int found_partitions = (acc_sum[iter] - (cursor > 0 ? acc_sum[cursor - 1] : 0) + modulo) % modulo;
            combinations[iter + 1] = found_partitions;
            acc_sum[iter + 1] = (acc_sum[iter] + found_partitions) % modulo;
        }
        return combinations[num_len];
    }
};
