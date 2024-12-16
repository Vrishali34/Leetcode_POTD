class Solution {
    public int[] getFinalState(int[] nums, int k, int multiplier) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]);
        for (int i = 0; i < nums.length; i++) pq.offer(new int[]{nums[i], i});
        while (k-- > 0) {
            int[] t = pq.poll();
            nums[t[1]] = t[0] * multiplier;
            pq.offer(new int[]{nums[t[1]], t[1]});
        }
        return nums;
    }
}
