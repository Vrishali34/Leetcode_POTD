class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
        int t_u_f = 0;
        boolean[] u_b = new boolean[baskets.length];
        for (int c_f : fruits) {
            boolean f_f = false;
            for (int i = 0; i < baskets.length; ++i) {
                if (!u_b[i] && baskets[i] >= c_f) {
                    u_b[i] = true;
                    f_f = true;
                    break;
                }
            }
            if (!f_f) {
                t_u_f++;
            }
        }
        return t_u_f;
    }
}
