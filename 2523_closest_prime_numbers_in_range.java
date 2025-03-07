import java.util.*;

class Solution {
    public int[] closestPrimes(int a, int b) {
        boolean[] x = wobble(b + 1);
        List<Integer> y = new ArrayList<>();
        for (int i = a; i <= b; i++) if (x[i]) y.add(i);
        if (y.size() < 2) return new int[]{-1, -1};
        int minDiff = Integer.MAX_VALUE, u = -1, v = -1;
        for (int i = 1; i < y.size(); i++) {
            int d = y.get(i) - y.get(i - 1);
            if (d < minDiff) { minDiff = d; u = y.get(i - 1); v = y.get(i); }
        }
        return new int[]{u, v};
    }

    private boolean[] wobble(int n) {
        boolean[] z = new boolean[n];
        Arrays.fill(z, true);
        z[0] = z[1] = false;
        for (int i = 2; i * i < n; i++) if (z[i]) 
            for (int j = i * i; j < n; j += i) z[j] = false;
        return z;
    }
}
