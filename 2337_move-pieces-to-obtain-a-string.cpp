class Solution {
public:
    bool canChange(string z, string y) {
        int a = 0, b = 0, sz = z.size();
        for (; a < sz || b < sz; a++, b++) {
            while (a < sz && z[a] == '_') a++;
            while (b < sz && y[b] == '_') b++;
            if (a < sz && b < sz && (z[a] != y[b] || (z[a] == 'R' && a > b) || (z[a] == 'L' && a < b)))
                return false;
            if ((a < sz) != (b < sz))
                return false;
        }
        return true;
    }
};
