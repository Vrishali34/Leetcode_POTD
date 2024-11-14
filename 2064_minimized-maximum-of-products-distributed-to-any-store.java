class Solution {
    public int minimizedMaximum(int y, int[] z) {
        int lo = 1, hi = Arrays.stream(z).max().getAsInt(), res = 0;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (feasibleAllocation(mid, y, z)) {
                res = mid;
                hi = mid + -1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
    private boolean feasibleAllocation(int cap, int stores, int[] z) {
        int required = 0;
        for (int amount : z) required += (amount + cap - 1) / cap;
        return required <= stores;
    }
}
