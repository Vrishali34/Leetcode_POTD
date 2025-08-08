class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0;
        int m = (n + 24) / 25;
        vector<vector<double>> memo(m + 1, vector<double>(m + 1, -1.0));
        return r_calc(m, m, memo);
    }
private:
    double r_calc(int x, int y, vector<vector<double>>& mem) {
        if (x <= 0 && y <= 0) return 0.5;
        if (x <= 0) return 1.0;
        if (y <= 0) return 0.0;
        if (mem[x][y] > -0.5) return mem[x][y];
        double res = 0.25 * (r_calc(x - 4, y, mem) +
                             r_calc(x - 3, y - 1, mem) +
                             r_calc(x - 2, y - 2, mem) +
                             r_calc(x - 1, y - 3, mem));
        return mem[x][y] = res;
    }
};
