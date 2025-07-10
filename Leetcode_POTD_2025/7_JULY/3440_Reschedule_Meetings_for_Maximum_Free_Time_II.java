class Solution {
    public int maxFreeTime(int eventTime, int[] startTime, int[] endTime) {
        int n = startTime.length, leftMax = 0, firstGap = startTime[0], ans = 0;
        List<Integer> gaps = new ArrayList<>();

        for (int i = 1; i < n; i++) gaps.add(startTime[i] - endTime[i - 1]);
        gaps.add(0, firstGap);
        gaps.add(eventTime - endTime[n - 1]);

        int[] suf = new int[gaps.size()];
        suf[gaps.size() - 1] = 0;
        for (int i = gaps.size() - 2; i >= 0; i--)
            suf[i] = Math.max(suf[i + 1], gaps.get(i + 1));

        for (int i = 1; i < gaps.size(); i++) {
            int dur = endTime[i - 1] - startTime[i - 1];
            if (dur <= Math.max(leftMax, suf[i]))
                ans = Math.max(ans, gaps.get(i - 1) + gaps.get(i) + dur);
            ans = Math.max(ans, gaps.get(i - 1) + gaps.get(i));
            leftMax = Math.max(leftMax, gaps.get(i - 1));
        }
        return ans;
    }
}
