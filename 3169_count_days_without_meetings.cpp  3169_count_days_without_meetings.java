class Solution {
public:
    int countDays(int k, vector<vector<int>>& m) {
        map<int, int> x;
        for (auto& v : m) x[v[0]]++, x[v[1] + 1]--;
        int c = 0, p = 1, z = 0;
        for (auto& [i, v] : x) {
            if (c == 0) z += i - p;
            c += v, p = i;
        }
        return z + (k >= p ? k - p + (c == 0) : 0);
    }
};
