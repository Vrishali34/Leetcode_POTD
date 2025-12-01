class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long stellar_sum = 0;
        for (int b : batteries) stellar_sum += b;
        sort(batteries.begin(), batteries.end());
        int star_count = n;
        int idx = batteries.size() - 1;
        while (idx >= 0 && batteries[idx] > stellar_sum / star_count) {
            stellar_sum -= batteries[idx];
            star_count--;
            idx--;
        }
        return stellar_sum / star_count;
    }
};
