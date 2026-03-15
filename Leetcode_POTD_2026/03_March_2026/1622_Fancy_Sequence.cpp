class Fancy {
    long long global_gain = 1, global_shift = 0;
    vector<long long> stream_data;
    const int core_mod = 1e9 + 7;

    long long compute_power(long long base, long long exp) {
        long long res = 1;
        for (; exp > 0; exp >>= 1, base = (base * base) % core_mod)
            if (exp & 1) res = (res * base) % core_mod;
        return res;
    }

    long long get_inverse(long long n) { return compute_power(n, core_mod - 2); }

public:
    Fancy() {}

    void append(int val) {
        long long raw_val = (val - global_shift + core_mod) % core_mod;
        stream_data.push_back((raw_val * get_inverse(global_gain)) % core_mod);
    }

    void addAll(int inc) {
        global_shift = (global_shift + inc) % core_mod;
    }

    void multAll(int m) {
        global_gain = (global_gain * m) % core_mod;
        global_shift = (global_shift * m) % core_mod;
    }

    int getIndex(int idx) {
        if (idx >= stream_data.size()) return -1;
        return (stream_data[idx] * global_gain + global_shift) % core_mod;
    }
};
