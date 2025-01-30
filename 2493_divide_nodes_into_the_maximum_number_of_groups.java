class Solution {
    boolean astral(int[][] g, int s, int[] hue, int clr) {
        hue[s] = clr;
        for (int[] e : g) {
            if (e[0] - 1 == s || e[1] - 1 == s) {
                int nxt = e[0] - 1 == s ? e[1] - 1 : e[0] - 1;
                if (hue[nxt] == clr || (hue[nxt] == -1 && !astral(g, nxt, hue, 1 - clr))) 
                    return false;
            }
        }
        return true;
    }
    
    int quantum(int[][] g, int s, int n) {
        boolean[] aura = new boolean[n];
        int lvl = 1;
        Queue<Integer> q = new LinkedList<>();
        q.add(s);
        aura[s] = true;
        while (!q.isEmpty()) {
            for (int sz = q.size(); sz > 0; sz--) {
                int p = q.poll();
                for (int[] e : g) {
                    int nxt = (e[0] - 1 == p) ? e[1] - 1 : (e[1] - 1 == p) ? e[0] - 1 : -1;
                    if (nxt != -1 && !aura[nxt]) {
                        aura[nxt] = true;
                        q.add(nxt);
                    }
                }
            }
            lvl++;
        }
        return lvl - 1;
    }

    int cosmic(int[][] g, int s, int n, boolean[] astr, int[] dims) {
        int zenith = dims[s];
        astr[s] = true;
        for (int[] e : g) {
            int nxt = (e[0] - 1 == s) ? e[1] - 1 : (e[1] - 1 == s) ? e[0] - 1 : -1;
            if (nxt != -1 && !astr[nxt]) 
                zenith = Math.max(zenith, cosmic(g, nxt, n, astr, dims));
        }
        return zenith;
    }

    public int magnificentSets(int n, int[][] edges) {
        int[] hue = new int[n], dims = new int[n];
        Arrays.fill(hue, -1);
        for (int i = 0; i < n; i++) 
            if (hue[i] == -1 && !astral(edges, i, hue, 1)) return -1;

        for (int i = 0; i < n; i++) 
            dims[i] = quantum(edges, i, n);
        
        int apex = 0;
        boolean[] astr = new boolean[n];
        for (int i = 0; i < n; i++) 
            if (!astr[i]) apex += cosmic(edges, i, n, astr, dims);
        return apex;
    }
}
