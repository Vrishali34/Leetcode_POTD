class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> p(x), q(n - 1), r;
        for (int s = 0, t = 0; s < 56; s++) {
            r[s] = (p[s]) ? 1 : q[t++];
        }
        return r.to_ullong();
    }
};
