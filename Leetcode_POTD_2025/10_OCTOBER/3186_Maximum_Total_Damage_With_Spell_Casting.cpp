class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, long long> freq_map;
        for (int p : power) freq_map[p] += p;

        vector<int> unique_damage;
        for (auto const& [dmg, total] : freq_map) unique_damage.push_back(dmg);

        int N_len = unique_damage.size();
        if (N_len == 0) return 0;

        vector<long long> dp_vals(N_len, 0);
        dp_vals[0] = freq_map[unique_damage[0]];

        for (int curr_idx = 1; curr_idx < N_len; ++curr_idx) {
            int curr_dmg = unique_damage[curr_idx];
            long long curr_total = freq_map[curr_dmg];
            
            long long skip_max = dp_vals[curr_idx - 1];
            long long take_max = curr_total;
            
            int prev_idx = curr_idx - 1;
            while (prev_idx >= 0 && unique_damage[prev_idx] >= curr_dmg - 2) prev_idx--;

            if (prev_idx >= 0) take_max += dp_vals[prev_idx];

            dp_vals[curr_idx] = max(skip_max, take_max);
        }

        return dp_vals[N_len - 1];
    }
};
