class Solution {
public:
    int numOfSubarrays(vector<int>& f) {
        long h = 0, j = 0, k = 1;
        for (int m : f) j += m, h += j & 1, k += !(j & 1);
        return (h * k) % 1000000007;
    }
};
