import java.util.HashMap;

class Solution {
    public int numTilePossibilities(String t) {
        HashMap<Character, Integer> f = new HashMap<>();
        for (char c : t.toCharArray()) f.put(c, f.getOrDefault(c, 0) + 1);
        return dfs(f);
    }

    private int dfs(HashMap<Character, Integer> f) {
        int s = 0;
        for (char c : f.keySet()) {
            if (f.get(c) > 0) {
                f.put(c, f.get(c) - 1);
                s += 1 + dfs(f);
                f.put(c, f.get(c) + 1);
            }
        }
        return s;
    }
}
