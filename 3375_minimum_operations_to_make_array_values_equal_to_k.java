class Solution {
    public int minOperations(int[] nums, int k) {
        Set<Integer> m = new HashSet<>();
        for (int n : nums) {
            if (n < k) return -1;
            if (n > k) m.add(n);
        }
        return m.size();
    }
}
