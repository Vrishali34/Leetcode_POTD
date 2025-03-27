class Solution {
public:
    int minimumIndex(vector<int>& z) {
        int x = 0, y = 0, m = z.size();
        unordered_map<int, int> f;
        for (int v : z) f[v]++;
        for (auto& [k, v] : f) if (v * 2 > m) x = k, y = v;
        int l = 0;
        for (int i = 0; i < m - 1; i++) {
            if ((l += z[i] == x) * 2 > i + 1 && (y - l) * 2 > m - i - 1) return i;
        }
        return -1;
    }
};
