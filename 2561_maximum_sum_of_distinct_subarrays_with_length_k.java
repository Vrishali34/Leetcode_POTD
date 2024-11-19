class Solution {
    public long maximumSubarraySum(int[] v, int w) {
        boolean[] mark = new boolean[100001];
        long sum = 0, maxSum = 0;
        for (int i = 0, j = 0, cnt = 0; j < v.length; j++) {
            sum += v[j];
            while (i < j && (cnt >= w || mark[v[j]])) {
                sum -= v[i];
                mark[v[i++]] = false;
                cnt--;
            }
            mark[v[j]] = true;
            cnt++;
            if (cnt == w) maxSum = Math.max(maxSum, sum);
        }
        return maxSum;
    }
}
