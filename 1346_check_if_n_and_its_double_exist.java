class Solution {
    public boolean checkIfExist(int[] a) {
        boolean[][] b = new boolean[2][1001];
        for (int v : a) {
            int w = Math.abs(v);
            if ((w <= 500 && b[v < 0 ? 1 : 0][2 * w]) || (w % 2 == 0 && b[v < 0 ? 1 : 0][w / 2]))
                return true;
            b[v < 0 ? 1 : 0][w] = true;
        }
        return false;
    }
}
