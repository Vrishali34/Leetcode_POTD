import java.util.*;

class Solution {
    public long repairCars(int[] r, int c) {
        long l = 0, h = (long) Arrays.stream(r).min().getAsInt() * c * c;
        while (l < h) {
            long m = (l + h) / 2, s = 0;
            for (int i : r) s += Math.sqrt(m / i);
            if (s >= c) h = m; else l = m + 1;
        }
        return l;
    }
}
