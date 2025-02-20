import java.util.*;

class Solution {
    public String findDifferentBinaryString(String[] nums) {
        Set<Integer> t = new HashSet<>();
        for (String x : nums) t.add(Integer.parseInt(x, 2));
        for (int k = 0; k <= nums.length; k++) 
            if (!t.contains(k)) return String.format("%" + nums.length + "s", Integer.toBinaryString(k)).replace(' ', '0');
        return "";
    }
}
