class Solution {
public:
    vector<int> resultsArray(vector<int>& a, int b) {
        int c = a.size(), d = 1;
        vector<int> e(c - b + 1, -1);
        for (int f = 1; f < b; f++) d = (a[f] == a[f - 1] + 1) ? d + 1 : 1;
        if (d == b) e[0] = a[b - 1];
        for (int g = 1, h = b; h < c; g++, h++) {
            d = (a[h] == a[h - 1] + 1) ? d + 1 : 1;
            if (d >= b) e[g] = a[h];
        }
        return e;
    }
};
