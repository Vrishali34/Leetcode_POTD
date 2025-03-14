#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& a, long long k) {
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        if (sum < k) return 0;
        int l = 1, r = sum / k;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (accumulate(a.begin(), a.end(), 0LL, [&](long long s, int x) { return s + x / m; }) < k)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }
};
