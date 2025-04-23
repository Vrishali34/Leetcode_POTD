class Solution {
public:
    int countLargestGroup(int z) {
        int x[37]{}, m = 0, c = 0;
        for (int i = 1; i <= z; ++i) m = max(m, ++x[acc(i)]);
        for (int i : x) if (i == m) ++c;
        return c;
    }
    int acc(int v) { int s = 0; while (v) s += v % 10, v /= 10; return s; }
};
