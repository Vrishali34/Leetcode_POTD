class Solution {
    public long pickGifts(int[] gifts, int k) {
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        long totalSum = 0;
        for (int gift : gifts) {
            maxHeap.add(gift);
            totalSum += gift;
        }
        while (k-- > 0) {
            int largest = maxHeap.poll();
            totalSum -= (largest - Math.sqrt(largest));
            maxHeap.add((int) Math.sqrt(largest));
        }
        return totalSum;
    }
}
