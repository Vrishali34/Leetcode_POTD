import java.util.HashMap;

class Solution {
    public int minimumLength(String x) {
        HashMap<Character, Integer> z = new HashMap<>();
        for (char y : x.toCharArray()) z.put(y, z.getOrDefault(y, 0) + 1);
        int d = 0;
        for (int count : z.values()) d += count > 2 ? count - (count % 2 == 1 ? 1 : 2) : 0;
        return x.length() - d;
    }
}
