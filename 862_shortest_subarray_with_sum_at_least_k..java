class Solution {
    public int shortestSubarray(int[] nums, int k) {
        int n = nums.length;
        long[] accSum = new long[n + 1];
        for (int i = 0; i < n; i++) accSum[i + 1] = accSum[i] + nums[i];
        Deque<Integer> idxQueue = new LinkedList<>();
        int minLen = Integer.MAX_VALUE;
        for (int i = 0; i <= n; i++) {
            while (!idxQueue.isEmpty() && accSum[i] - accSum[idxQueue.peekFirst()] >= k) {
                minLen = Math.min(minLen, i - idxQueue.pollFirst());
            }
            while (!idxQueue.isEmpty() && accSum[i] <= accSum[idxQueue.peekLast()]) {
                idxQueue.pollLast();
            }
            idxQueue.addLast(i);
        }
        return minLen == Integer.MAX_VALUE ? -1 : minLen;
    }
}
