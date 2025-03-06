class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& G) {
        int n = G.size(), N = n * n, X = 0, Y = 0, Z = 0;
        for (int i = 1; i <= N; i++) Z ^= i;
        for (auto& r : G) for (int v : r) Z ^= v;
        int lsb = Z & -Z;
        for (int i = 1; i <= N; i++) (i & lsb) ? X ^= i : Y ^= i;
        for (auto& r : G) for (int v : r) (v & lsb) ? X ^= v : Y ^= v;
        for (auto& r : G) for (int v : r) if (v == X) return {X, Y};
        return {Y, X};
    }
};
