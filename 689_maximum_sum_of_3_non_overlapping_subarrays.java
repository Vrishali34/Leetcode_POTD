import java.util.*;

class Solution {
    public int[] maxSumOfThreeSubarrays(int[] x, int y) {
        int a = x.length, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, i = 0, j = y, k = 2 * y;
        int[] z = {0, y, 2 * y};
        for (int p = 0; p < y; p++) {
            b += x[p];
            c += x[p + y];
            d += x[p + 2 * y];
        }
        e = b;
        f = b + c;
        g = b + c + d;
        for (int m = 0; m <= a - 3 * y; m++) {
            if (m > 0) {
                b += x[m + y - 1] - x[m - 1];
                c += x[m + 2 * y - 1] - x[m + y - 1];
                d += x[m + 3 * y - 1] - x[m + 2 * y - 1];
            }
            if (b > e) {
                e = b;
                h = m;
            }
            if (e + c > f) {
                f = e + c;
                i = h;
                j = m + y;
            }
            if (f + d > g) {
                g = f + d;
                z = new int[]{i, j, m + 2 * y};
            }
        }
        return z;
    }
}
