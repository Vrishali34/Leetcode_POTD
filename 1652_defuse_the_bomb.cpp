class Solution {
public:
    vector<int> decrypt(vector<int>& d, int e) {
        int f = d.size();
        vector<int> g(f, 0);
        if (!e) return g;
        d.insert(d.end(), d.begin(), d.end());
        for (int i = 0; i < f; i++) {
            int h = 0;
            for (int j = 1; j <= abs(e); j++) 
                h += d[i + (e > 0 ? j : f - j)];
            g[i] = h;
        }
        return g;
    }
};
