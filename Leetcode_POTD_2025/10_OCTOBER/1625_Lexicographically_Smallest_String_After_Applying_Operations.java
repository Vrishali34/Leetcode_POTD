import java.util.ArrayDeque;
import java.util.HashSet;
import java.util.Queue;
import java.util.Set;

class Solution {
    private String apply_add_op(String s_in, int a_val) {
        char[] arr = s_in.toCharArray();
        for (int i = 1; i < arr.length; i += 2) {
            arr[i] = (char) (((arr[i] - '0' + a_val) % 10) + '0');
        }
        return new String(arr);
    }

    private String apply_rot_op(String s_in, int b_val) {
        int len = s_in.length();
        b_val %= len;
        if (b_val == 0) return s_in;
        return s_in.substring(len - b_val) + s_in.substring(0, len - b_val);
    }

    public String findLexSmallestString(String s, int a, int b) {
        Set<String> nebula_set = new HashSet<>();
        Queue<String> path_queue = new ArrayDeque<>();
        String stellar_core = s;

        path_queue.offer(s);
        nebula_set.add(s);

        while (!path_queue.isEmpty()) {
            String current_star = path_queue.poll();
            
            if (current_star.compareTo(stellar_core) < 0) {
                stellar_core = current_star;
            }

            String next_add = apply_add_op(current_star, a);
            if (!nebula_set.contains(next_add)) {
                nebula_set.add(next_add);
                path_queue.offer(next_add);
            }

            String next_rot = apply_rot_op(current_star, b);
            if (!nebula_set.contains(next_rot)) {
                nebula_set.add(next_rot);
                path_queue.offer(next_rot);
            }
        }
        return stellar_core;
    }
}
