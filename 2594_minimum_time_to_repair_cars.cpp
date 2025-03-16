#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    long long repairCars(vector<int>& v, int c) {
        long long l = 0, r = 1LL * *min_element(v.begin(), v.end()) * c * c;
        while (l < r) {
            long long m = (l + r) / 2, s = 0;
            for (int i : v) s += sqrt(m / i);
            s >= c ? r = m : l = m + 1;
        }
        return l;
    }
};
