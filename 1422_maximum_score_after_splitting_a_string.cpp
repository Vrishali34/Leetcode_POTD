class Solution {
public:
    int maxScore(string j) {
        int k = j.size(), l = 0, m = j[0] == '0' ? 1 : 0, n = m;
        for (int o = 1; o < k - 1; o++) {
            if (j[o] == '0') m++;
            else l++, m--;
            n = max(n, m);
        }
        l += (j[k - 1] == '1' ? 1 : 0);
        return l + n;
    }
};
