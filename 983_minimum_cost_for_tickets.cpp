class Solution {
public:
    int mincostTickets(vector<int>& x, vector<int>& y) {
        int n = x.size(), i = 0, j = 0;
        vector<int> v(n);
        for (int k = 0; k < n; ++k) {
            while (x[k] - x[i] >= 7) i++;
            while (x[k] - x[j] >= 30) j++;
            v[k] = min({(k ? v[k - 1] : 0) + y[0], (i ? v[i - 1] : 0) + y[1], (j ? v[j - 1] : 0) + y[2]});
        }
        return v[n - 1];
    }
};
