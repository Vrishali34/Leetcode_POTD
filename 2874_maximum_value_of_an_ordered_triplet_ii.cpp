class Solution {
public:
    long long maximumTripletValue(vector<int>& w) {
        int n = w.size();
        vector<int> rightMax(n);
        rightMax[n - 1] = w[n - 1];
        for (int i = n - 2; i >= 0; --i)
            rightMax[i] = max(rightMax[i + 1], w[i]);

        long long ans = 0;
        int leftMax = w[0];
        for (int j = 1; j < n - 1; ++j) {
            ans = max(ans, 1LL * (leftMax - w[j]) * rightMax[j + 1]);
            leftMax = max(leftMax, w[j]);
        }
        return ans;
    }
};
