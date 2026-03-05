class Solution {
public:
    int minOperations(string s) {
        int swap_count = 0, sz = s.size();
        for (int i = 0; i < sz; ++i)
            if (s[i] - '0' != i % 2) swap_count++;
        return min(swap_count, sz - swap_count);
    }
};
