class Solution {
public:
    bool canConstruct(string z, int x) {
        if (x > z.size()) return false;
        int y[26] = {};
        for (char c : z) y[c - 'a']++;
        int w = 0;
        for (int i : y) w += i % 2;
        return w <= x;
    }
};
