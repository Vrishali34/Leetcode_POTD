class Solution {
public:
    int minOperations(vector<vector<int>>& g, int d) {
        vector<int> v;
        for (auto& r : g) for (int a : r) v.push_back(a);
        for (int& a : v) if ((a - v[0]) % d) return -1;
        nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
        int z = v[v.size() / 2], r = 0;
        for (int a : v) r += abs(a - z) / d;
        return r;
    }
};
