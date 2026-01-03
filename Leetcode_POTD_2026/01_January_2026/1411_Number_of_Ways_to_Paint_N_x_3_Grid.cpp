class Solution {
public:
    int numOfWays(int n) {
        long dual_clr = 6, trio_clr = 6, mod_val = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            long next_dual = (dual_clr * 3 + trio_clr * 2) % mod_val;
            trio_clr = (dual_clr * 2 + trio_clr * 2) % mod_val;
            dual_clr = next_dual;
        }
        return (dual_clr + trio_clr) % mod_val;
    }
};
