class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const unsigned long long mod = (1ULL << 61) - 1;
        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        unsigned long long base = rng() % (mod - 200000) + 100000;
        auto mul_mod = [&](unsigned long long a, unsigned long long b) {
            __uint128_t prod = (__uint128_t)a * b;
            unsigned long long res = (unsigned long long)(prod & mod) + (unsigned long long)(prod >> 61);
            return res >= mod ? res - mod : res;
        };
        vector<unsigned long long> pref(n + 1, 0), pw(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = (mul_mod(pref[i], base) + nums[i]) % mod;
            pw[i + 1] = mul_mod(pw[i], base);
        }
        auto has_unique = [&](int len) {
            vector<unsigned long long> hash_list;
            for (int i = 0; i + len <= n; i++)
                hash_list.push_back((pref[i + len] + mod - mul_mod(pref[i], pw[len])) % mod);
            sort(hash_list.begin(), hash_list.end());
            int cnt = hash_list.size();
            for (int i = 0; i < cnt; i++)
                if ((i == 0 || hash_list[i] != hash_list[i - 1]) && (i == cnt - 1 || hash_list[i] != hash_list[i + 1]))
                    return true;
            return false;
        };
        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (has_unique(mid)) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};
