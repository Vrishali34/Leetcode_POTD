class Solution {
    public long countFairPairs(int[] data, int low, int high) {
        long result = 0;
        Arrays.sort(data);
        for (int idx = 0; idx < data.length - 1; idx++) {
            int upper = Arrays.binarySearch(data, idx + 1, data.length, high - data[idx] + 1);
            int lower = Arrays.binarySearch(data, idx + 1, data.length, low - data[idx]);
            if (upper < 0) upper = -(upper + 1);
            if (lower < 0) lower = -(lower + 1);
            result += upper - lower;
        }
        return result;
    }
}
