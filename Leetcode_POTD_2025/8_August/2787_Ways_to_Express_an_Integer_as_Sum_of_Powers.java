import java.util.ArrayList;

class Solution {
    public int numberOfWays(int n, int x) {
        long g_mod = 1_000_000_007;
        long[] celestial_ways = new long[n + 1];
        celestial_ways[0] = 1;

        for (int b_c = 1; ; ++b_c) {
            long stardust_power = (long)Math.pow(b_c, x);
            if (stardust_power > n) {
                break;
            }
            for (int s_t = n; s_t >= stardust_power; --s_t) {
                celestial_ways[s_t] = (celestial_ways[s_t] + celestial_ways[(int)(s_t - stardust_power)]) % g_mod;
            }
        }
        return (int)celestial_ways[n];
    }
}
