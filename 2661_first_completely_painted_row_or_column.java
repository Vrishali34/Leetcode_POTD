class Solution {  
    public int firstCompleteIndex(int[] x, int[][] y) {  
        int m = y.length, n = y[0].length;  
        Map<Integer, int[]> z = new HashMap<>();  
        int[] a = new int[m], b = new int[n];  
        Arrays.fill(a, n);  
        Arrays.fill(b, m);  
        for (int i = 0; i < m; ++i)  
            for (int j = 0; j < n; ++j)  
                z.put(y[i][j], new int[]{i, j});  
        for (int k = 0; k < x.length; ++k) {  
            int[] p = z.get(x[k]);  
            if (--a[p[0]] == 0 || --b[p[1]] == 0) return k;  
        }  
        return -1;  
    }  
}  
