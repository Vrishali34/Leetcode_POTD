class Solution {
    public int countCompleteComponents(int w, int[][] x) {
        List<List<Integer>> y = new ArrayList<>();
        for (int i = 0; i < w; i++) y.add(new ArrayList<>());
        for (int[] z : x) {
            y.get(z[0]).add(z[1]);
            y.get(z[1]).add(z[0]);
        }
        boolean[] u = new boolean[w];
        List<Integer> a = new ArrayList<>();
        int c = 0;

        for (int i = 0; i < w; i++) {
            if (!u[i]) {
                a.clear();
                dfs(i, u, y, a);
                int e = 0;
                for (int j : a) e += y.get(j).size();
                if (e / 2 == a.size() * (a.size() - 1) / 2) c++;
            }
        }
        return c;
    }

    void dfs(int i, boolean[] u, List<List<Integer>> y, List<Integer> a) {
        u[i] = true;
        a.add(i);
        for (int j : y.get(i)) if (!u[j]) dfs(j, u, y, a);
    }
}
