class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n_len = nums.size();
        if (n_len <= 1) return 0;
        int max_num = 0;
        for (int val : nums) if (val > max_num) max_num = val;
        
        vector<int> min_prime(max_num + 1);
        for (int i = 0; i <= max_num; ++i) min_prime[i] = i;
        for (int p = 2; p * p <= max_num; ++p) {
            if (min_prime[p] == p) {
                for (int m = p * p; m <= max_num; m += p)
                    if (min_prime[m] == m) min_prime[m] = p;
            }
        }

        vector<vector<int>> num_indices(max_num + 1);
        for (int idx = 0; idx < n_len; ++idx) {
            int temp_num = nums[idx];
            while (temp_num > 1) {
                int factor = min_prime[temp_num];
                num_indices[factor].push_back(idx);
                while (temp_num % factor == 0) temp_num /= factor;
            }
        }

        queue<int> jump_q;
        jump_q.push(0);
        vector<int> jump_dist(n_len, -1);
        jump_dist[0] = 0;
        vector<bool> prime_used(max_num + 1, false);

        while (!jump_q.empty()) {
            int curr_idx = jump_q.front();
            jump_q.pop();
            if (curr_idx == n_len - 1) return jump_dist[curr_idx];

            int adj_moves[] = {curr_idx - 1, curr_idx + 1};
            for (int next_idx : adj_moves) {
                if (next_idx >= 0 && next_idx < n_len && jump_dist[next_idx] == -1) {
                    jump_dist[next_idx] = jump_dist[curr_idx] + 1;
                    jump_q.push(next_idx);
                }
            }

            int val_at_idx = nums[curr_idx];
            if (val_at_idx > 1 && min_prime[val_at_idx] == val_at_idx && !prime_used[val_at_idx]) {
                prime_used[val_at_idx] = true;
                for (int target_idx : num_indices[val_at_idx]) {
                    if (jump_dist[target_idx] == -1) {
                        jump_dist[target_idx] = jump_dist[curr_idx] + 1;
                        jump_q.push(target_idx);
                    }
                }
            }
        }
        return -1;
    }
};
