class Solution {
public:
    int maxCount(vector<int>& a, int b, int c) {
        unordered_set<int> d(a.begin(), a.end());
        int e = 0, f = 0;
        for (int g = 1; g <= b; ++g) {
            if (d.count(g)) continue;
            e += g;
            if (e > c) break;
            ++f;
        }
        return f;
    }
};
