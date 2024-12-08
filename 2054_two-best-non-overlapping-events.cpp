class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        int sz = ev.size(), mxVal = 0;
        sort(ev.begin(), ev.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
        vector<int> maxSuffix(sz);
        maxSuffix[sz - 1] = ev[sz - 1][2];
        for (int i = sz - 2; i >= 0; --i) maxSuffix[i] = max(ev[i][2], maxSuffix[i + 1]);
        for (int i = 0; i < sz; ++i) {
            int lo = i + 1, hi = sz - 1, idx = -1;
            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;
                if (ev[mid][0] > ev[i][1]) idx = mid, hi = mid - 1;
                else lo = mid + 1;
            }
            if (idx != -1) mxVal = max(mxVal, ev[i][2] + maxSuffix[idx]);
            mxVal = max(mxVal, ev[i][2]);
        }
        return mxVal;
    }
};
