class Solution {
public:
    int minFlips(string s) {
        int n = s.size(), best_ops = n;
        string double_s = s + s;
        int diff_p1 = 0, diff_p2 = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (double_s[i] != (i % 2 ? '1' : '0')) diff_p1++;
            if (double_s[i] != (i % 2 ? '0' : '1')) diff_p2++;
            if (i >= n) {
                if (double_s[i - n] != ((i - n) % 2 ? '1' : '0')) diff_p1--;
                if (double_s[i - n] != ((i - n) % 2 ? '0' : '1')) diff_p2--;
            }
            if (i >= n - 1) best_ops = min({best_ops, diff_p1, diff_p2});
        }
        return best_ops;
    }
};
