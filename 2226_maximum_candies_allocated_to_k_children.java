import java.util.*;

class Solution {
    public int maximumCandies(int[] a, long k) {
        long sum = 0;
        for (int x : a) sum += x;
        if (sum < k) return 0;  
        int l = 1, r = (int) (sum / k);
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (Arrays.stream(a).map(x -> x / m).asLongStream().sum() < k) r = m - 1;
            else l = m;
        }
        return l;
    }
}
