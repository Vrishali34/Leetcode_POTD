class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        const long long MOD = 1e9 + 7;
        vector<long long> diffTree(n + 2, 0), weightTree(n + 2, 0);
        long long totalSum = 0;

        auto pointUpdate = [&](int pos, long long delta, long long weightDelta) {
            for (++pos; pos <= n + 1; pos += pos & (-pos)) {
                diffTree[pos] += delta;
                weightTree[pos] += weightDelta;
            }
        };
        auto prefixSum = [&](int cnt) -> long long {
            long long sum = 0, weightSum = 0;
            for (int pos = cnt; pos > 0; pos -= pos & (-pos)) {
                sum += diffTree[pos];
                weightSum += weightTree[pos];
            }
            return (long long)cnt * sum + weightSum;
        };
        auto rangeAdd = [&](int lo, int hi) {
            pointUpdate(lo, 1, -(long long)lo);
            pointUpdate(hi + 1, -1, (long long)(hi + 1));
            totalSum += hi - lo + 1;
        };
        auto suffixSum = [&](int lo) -> long long {
            return totalSum - prefixSum(lo);
        };

        vector<int> lastSeenAt(100001, 0);
        long long endHere = 0, ans = 0;

        for (int idx = 0; idx < n; idx++) {
            int curVal = nums[idx];
            int prevEnd = lastSeenAt[curVal];

            endHere += 2 * suffixSum(prevEnd) + (idx - prevEnd + 1);
            ans += endHere;

            rangeAdd(prevEnd, idx);
            lastSeenAt[curVal] = idx + 1;
        }

        return (int)(ans % MOD);
    }
};
