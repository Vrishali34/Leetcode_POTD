class Solution {
    public int minOperations(int[][] m, int d) {
        List<Integer> a = new ArrayList<>();
        for (int[] r : m) for (int n : r) a.add(n);
        int b = a.get(0);
        for (int n : a) if ((n - b) % d != 0) return -1;
        Collections.sort(a);
        int t = a.get(a.size()/2), s = 0;
        for (int n : a) s += Math.abs(n - t) / d;
        return s;
    }
}
