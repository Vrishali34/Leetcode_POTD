#include <vector>
#include <cmath>

class Solution {
public:
    int numberOfWays(int n, int x) {
        long long g_mod = 1e9 + 7;
        std::vector<long long> celestial_ways(n + 1, 0);
        celestial_ways[0] = 1;

        for (int b_c = 1; ; ++b_c) {
            long long stardust_power = pow(b_c, x);
            if (stardust_power > n) {
                break;
            }
            for (int s_t = n; s_t >= stardust_power; --s_t) {
                celestial_ways[s_t] = (celestial_ways[s_t] + celestial_ways[s_t - stardust_power]) % g_mod;
            }
        }
        return celestial_ways[n];
    }
};
