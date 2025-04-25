class Solution {
public:
    long long countInterestingSubarrays(vector<int>& a, int b, int c) {
        unordered_map<int, long long> d; d[0]++;
        long long e = 0, f = 0;
        for (auto g : a) {
            f += (g % b == c);
            e += d[(f - c + b) % b];
            d[f % b]++;
        }
        return e;
    }
};
