class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int sz = colors.size(), lo = 0, hi = sz - 1;
        while (colors[hi] == colors[0]) hi--;
        while (colors[lo] == colors[sz - 1]) lo++;
        return max(hi, (sz - 1) - lo);
    }
};
