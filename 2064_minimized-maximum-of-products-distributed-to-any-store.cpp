class Solution {
public:
    int minimizedMaximum(int p, vector<int>& q) {
        int lo = 1, hi = *max_element(q.begin(), q.end()), res = 0;
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (isFine(mi, p, q)) res = mi, hi = mi - 1;
            else lo = mi + 1;
        }
        return res;
    }
private:
    bool isFine(int mx, int p, const vector<int>& q) {
        int k = 0;
        for (int j : q) k += (j + mx - 1) / mx;
        return k <= p;
    }
};
