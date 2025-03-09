class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& w, int p) {
        int r = 0, t = 1, n = w.size();
        for (int i = 1; i < n + p - 1; i++) {
            t = (w[i % n] == w[(i - 1) % n]) ? 1 : t + 1;
            r += (t >= p);
        }
        return r;
    }
};
