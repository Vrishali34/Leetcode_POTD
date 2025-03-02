class Solution {
    public int[][] mergeArrays(int[][] a, int[][] b) {
        List<int[]> r = new ArrayList<>();
        int x = 0, y = 0;
        while (x < a.length || y < b.length) {
            if (y == b.length || (x < a.length && a[x][0] < b[y][0])) r.add(a[x++]);
            else if (x == a.length || (y < b.length && a[x][0] > b[y][0])) r.add(b[y++]);
            else r.add(new int[]{a[x][0], a[x++][1] + b[y++][1]});
        }
        return r.toArray(new int[0][]);
    }
}
