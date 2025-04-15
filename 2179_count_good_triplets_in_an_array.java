class Solution {
    public long goodTriplets(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] pos = new int[n];
        for (int i = 0; i < n; i++) pos[nums1[i]] = i;

        int[] mapped = new int[n];
        for (int i = 0; i < n; i++) mapped[i] = pos[nums2[i]];

        BIT bit = new BIT(n);
        int[] left = new int[n];
        for (int i = 0; i < n; i++) {
            left[i] = bit.query(mapped[i]);
            bit.update(mapped[i] + 1, 1);
        }

        bit = new BIT(n);
        int[] right = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            right[i] = bit.query(n) - bit.query(mapped[i] + 1);
            bit.update(mapped[i] + 1, 1);
        }

        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long) left[i] * right[i];
        }
        return ans;
    }

    class BIT {
        int[] tree;
        int size;

        BIT(int n) {
            size = n + 2;
            tree = new int[size];
        }

        void update(int i, int val) {
            while (i < size) {
                tree[i] += val;
                i += i & -i;
            }
        }

        int query(int i) {
            int res = 0;
            while (i > 0) {
                res += tree[i];
                i -= i & -i;
            }
            return res;
        }
    }
}
