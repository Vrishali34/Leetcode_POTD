class Solution {
    public int tupleSameProduct(int[] x) {
        Map<Integer, Integer> y = new HashMap<>();
        int z = 0;
        for (int i = 0; i < x.length; i++)
            for (int j = i + 1; j < x.length; j++)
                y.put(x[i] * x[j], y.getOrDefault(x[i] * x[j], 0) + 1);
        for (int v : y.values())
            z += v * (v - 1) * 4;
        return z;
    }
}
