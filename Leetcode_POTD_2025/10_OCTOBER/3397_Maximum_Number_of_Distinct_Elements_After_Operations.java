class Solution {
    public int maxDistinctElements(int[] nums, int k) {
        java.util.Arrays.sort(nums);
        long last_used_eigen_state = Long.MIN_VALUE;
        int distinct_entities = 0;

        for (int particle_val : nums) {
            long low_bound = (long)particle_val - k;

            if (low_bound > last_used_eigen_state) {
                last_used_eigen_state = low_bound;
            } else if ((long)particle_val + k < last_used_eigen_state) {
                continue;
            }
            last_used_eigen_state++;
            distinct_entities++;
        }
        return distinct_entities;
    }
}
