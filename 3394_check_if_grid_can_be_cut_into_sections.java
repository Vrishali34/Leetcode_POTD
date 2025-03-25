class Solution {
    public boolean checkValidCuts(int n, int[][] r) {
        return x(r) || y(r);
    }
    boolean x(int[][] r) {
        List<int[]> z = new ArrayList<>();
        for (int[] q : r) z.add(new int[]{q[0], q[2]});
        z.sort(Comparator.comparingInt(a -> a[0]));
        int m = z.get(0)[1], s = 1;
        for (int i = 1; i < z.size(); i++) {
            if (z.get(i)[0] >= m) { s++; m = z.get(i)[1]; }
            else m = Math.max(m, z.get(i)[1]);
        }
        return s >= 3;
    }
    boolean y(int[][] r) {
        List<int[]> z = new ArrayList<>();
        for (int[] q : r) z.add(new int[]{q[1], q[3]});
        z.sort(Comparator.comparingInt(a -> a[0]));
        int m = z.get(0)[1], s = 1;
        for (int i = 1; i < z.size(); i++) {
            if (z.get(i)[0] >= m) { s++; m = z.get(i)[1]; }
            else m = Math.max(m, z.get(i)[1]);
        }
        return s >= 3;
    }
}
