class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int coin_cnt = coins.size();
        vector<long long> lcm_subset(1 << coin_cnt, 1);

        for (int mask = 1; mask < (1 << coin_cnt); mask++) {
            long long curr_lcm = 1;
            for (int bit_pos = 0; bit_pos < coin_cnt; bit_pos++) {
                if (mask & (1 << bit_pos)) {
                    long long gcd_val = __gcd(curr_lcm, (long long)coins[bit_pos]);
                    curr_lcm = curr_lcm / gcd_val * coins[bit_pos];
                    if (curr_lcm > (long long)2e9 * 30) { curr_lcm = -1; break; }
                }
            }
            lcm_subset[mask] = curr_lcm;
        }

        long long lo = 1, hi = (long long)25 * k;
        while (lo < hi) {
            long long mid_val = lo + (hi - lo) / 2;
            long long amount_cnt = 0;

            for (int mask = 1; mask < (1 << coin_cnt); mask++) {
                if (lcm_subset[mask] == -1) continue;
                int bit_cnt = __builtin_popcount(mask);
                long long term = mid_val / lcm_subset[mask];
                amount_cnt += (bit_cnt % 2 == 1) ? term : -term;
            }

            if (amount_cnt >= k) hi = mid_val;
            else lo = mid_val + 1;
        }

        return lo;
    }
};
