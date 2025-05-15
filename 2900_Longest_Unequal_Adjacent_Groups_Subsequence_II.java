import java.util.*;

public class Solution {
    public List<String> getLongestSubsequence(String[] q, int[] v) {
        List<String> p = new ArrayList<>();
        int l = -1;
        for (int i = 0; i < q.length; ++i) {
            if (l == -1 || v[i] != v[l]) {
                p.add(q[i]);
                l = i;
            }
        }
        return p;
    }
}
