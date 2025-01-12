class Solution {
public:
    bool canBeValid(string a, string b) {
        int c = a.size(), d = 0;
        if (c % 2) return 0;
        for (int e = 0; e < c; e++) {
            d += (a[e] == '(' || b[e] == '0') ? 1 : -1;
            if (d < 0) return 0;
        }
        d = 0;
        for (int e = c - 1; e >= 0; e--) {
            d += (a[e] == ')' || b[e] == '0') ? 1 : -1;
            if (d < 0) return 0;
        }
        return 1;
    }
};
