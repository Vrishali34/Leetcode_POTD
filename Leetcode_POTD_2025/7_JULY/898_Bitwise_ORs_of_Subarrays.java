import java.util.HashSet;
import java.util.Set;

class Solution {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> uniqueOrs = new HashSet<>();
        Set<Integer> currentOrs = new HashSet<>();
        for (int x : arr) {
            Set<Integer> nextOrs = new HashSet<>();
            nextOrs.add(x);
            for (int y : currentOrs) {
                nextOrs.add(x | y);
            }
            currentOrs = nextOrs;
            uniqueOrs.addAll(currentOrs);
        }
        return uniqueOrs.size();
    }
}
