class Solution {
public:
    int minimumRecolors(string x, int y) {
        int a = 0, b = 0;
        for (int i = 0; i < y; i++) a += x[i] == 'W';
        b = a;
        for (int i = y; i < x.size(); i++) {
            a += x[i] == 'W';
            a -= x[i - y] == 'W';
            b = min(b, a);
        }
        return b;
    }
};
