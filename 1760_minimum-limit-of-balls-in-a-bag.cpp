class Solution {
public:
    int minimumSize(vector<int>& g, int o) {
        int x = 1, y = *max_element(g.begin(), g.end());
        while (x < y) {
            int m = (x + y) >> 1, f = 0;
            for (auto t : g) f += (t - 1) / m;
            f > o ? x = m + 1 : y = m;
        }
        return x;
    }
};
