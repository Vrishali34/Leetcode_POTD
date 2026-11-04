class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size(), lowSize = (x + 1) / 2;
        multiset<int> lowHalf, highHalf;
        long long lowSum = 0, highSum = 0;
        vector<long long> winCost(n - x + 1);

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (lowHalf.empty() || val <= *lowHalf.rbegin()) lowHalf.insert(val), lowSum += val;
            else highHalf.insert(val), highSum += val;

            if (i >= x) {
                int outVal = nums[i - x];
                if (outVal <= *lowHalf.rbegin()) lowHalf.erase(lowHalf.find(outVal)), lowSum -= outVal;
                else highHalf.erase(highHalf.find(outVal)), highSum -= outVal;
            }

            while ((int)lowHalf.size() > lowSize) {
                int top = *lowHalf.rbegin();
                lowHalf.erase(prev(lowHalf.end()));
                highHalf.insert(top);
                lowSum -= top, highSum += top;
            }
            while ((int)lowHalf.size() < lowSize && !highHalf.empty()) {
                int top = *highHalf.begin();
                highHalf.erase(highHalf.begin());
                lowHalf.insert(top);
                lowSum += top, highSum -= top;
            }

            if (i >= x - 1) {
                long long medVal = *lowHalf.rbegin();
                winCost[i - x + 1] = medVal * lowHalf.size() - lowSum + highSum - medVal * highHalf.size();
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prevDp(n + 1, 0), currDp(n + 1);
        for (int grp = 1; grp <= k; grp++) {
            fill(currDp.begin(), currDp.end(), INF);
            for (int i = x; i <= n; i++)
                currDp[i] = min(currDp[i - 1], prevDp[i - x] + winCost[i - x]);
            swap(prevDp, currDp);
        }
        return prevDp[n];
    }
};
