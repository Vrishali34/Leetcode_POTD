class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& y) {
        int c = y.size(), j = 0;
        while (j + 1 < c && y[j] <= y[j + 1]) j++;
        if (j == c - 1) return 0;
        int k = c - 1;
        while (k > j && y[k - 1] <= y[k]) k--;
        int w = min(c - j - 1, k);
        for (int v = 0, b = k; v <= j && b < c; )
            if (y[v] <= y[b]) w = min(w, b - v - 1), v++;
            else b++;
        return w;
    }
};
