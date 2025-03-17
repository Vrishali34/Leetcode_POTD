class Solution {
    public boolean divideArray(int[] x) {
        Map<Integer, Integer> y = new HashMap<>();
        for (int z : x) y.put(z, y.getOrDefault(z, 0) + 1);
        for (int b : y.values()) if (b % 2 != 0) return false;
        return true;
    }
}
