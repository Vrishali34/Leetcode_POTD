class Solution {
    public int numRabbits(int[] y) {
        var t = new HashMap<Integer, Integer>();
        int z = 0;
        for (int a : y) {
            int c = t.getOrDefault(a, 0);
            if (c % (a + 1) == 0) z += a + 1;
            t.put(a, c + 1);
        }
        return z;
    }
}
