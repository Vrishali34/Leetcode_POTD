class Solution {
    public int minNumberOperations(int[] target) {
        int t_size = target.length;
        int min_ops = target[0];
        int prev_val = target[0];
        for (int i = 1; i < t_size; i++) {
            if (target[i] > prev_val) {
                min_ops += target[i] - prev_val;
            }
            prev_val = target[i];
        }
        return min_ops;
    }
}
