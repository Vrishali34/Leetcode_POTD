import java.util.Arrays;

class Solution {
    public long minTime(int[] vertex, int[] conduit) {
        int v_size = vertex.length;
        long[] v_track = new long[v_size];

        for (int c_val : conduit) {
            // 1. Base
            v_track[0] = v_track[0] + (long)vertex[0] * c_val;

            // 2. Forward Propagate
            for (int k = 1; k < v_size; k++) {
                long proc_time = (long)vertex[k] * c_val;
                v_track[k] = Math.max(v_track[k], v_track[k - 1]) + proc_time;
            }

            // 3. Backward Adjust
            for (int k = v_size - 2; k >= 0; k--) {
                long proc_time_next = (long)vertex[k + 1] * c_val;
                v_track[k] = v_track[k + 1] - proc_time_next;
            }
        }
        return v_track[v_size - 1];
    }
}
