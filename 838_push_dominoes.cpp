class Solution {
public:
    string pushDominoes(string a) {
        int i = 0, n = a.size();
        while (i < n) {
            if (a[i] != '.') { ++i; continue; }
            int j = i;
            while (j < n && a[j] == '.') ++j;
            char l = i ? a[i - 1] : '.', r = j < n ? a[j] : '.';
            if (l == 'R' && r == 'L') {
                int k = j - i;
                for (int x = 0; x < k / 2; ++x) a[i + x] = 'R', a[j - 1 - x] = 'L';
            } else if (l == 'R') fill(a.begin() + i, a.begin() + j, 'R');
            else if (r == 'L') fill(a.begin() + i, a.begin() + j, 'L');
            i = j;
        }
        return a;
    }
};
