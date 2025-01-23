class Solution {
    public int countServers(int[][] v) {
        int[] t = new int[v.length], u = new int[v[0].length];
        for (int n = 0; n < v.length; n++) {
            for (int l = 0; l < v[0].length; l++) {
                t[n] += v[n][l];
                u[l] += v[n][l];
            }
        }
        int k = 0;
        for (int n = 0; n < v.length; n++) {
            for (int l = 0; l < v[0].length; l++) {
                if (v[n][l] == 1 && (t[n] > 1 || u[l] > 1)) k++;
            }
        }
        return k;
    }
}
