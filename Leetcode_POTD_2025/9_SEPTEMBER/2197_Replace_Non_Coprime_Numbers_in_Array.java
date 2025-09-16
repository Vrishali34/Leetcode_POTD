import java.util.*;

class Solution {
    private int the_gcd_finder(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        LinkedList<Integer> the_lcm_maker = new LinkedList<>();
        for (int the_num : nums) {
            the_lcm_maker.add(the_num);
            while (the_lcm_maker.size() > 1) {
                int a = the_lcm_maker.get(the_lcm_maker.size() - 1);
                int b = the_lcm_maker.get(the_lcm_maker.size() - 2);
                int common_divisor = the_gcd_finder(a, b);
                if (common_divisor == 1) {
                    break;
                }
                long product = (long) a * b;
                int lcm_result = (int) (product / common_divisor);
                the_lcm_maker.removeLast();
                the_lcm_maker.removeLast();
                the_lcm_maker.add(lcm_result);
            }
        }
        return the_lcm_maker;
    }
}
