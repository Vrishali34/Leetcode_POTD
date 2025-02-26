class Solution {
public:
    int maxAbsoluteSum(vector<int>& q) {
        int a = 0, b = 0, c = 0;
        for (int w : q) c += w, a = max(a, c), b = min(b, c);
        return a - b;
    }
};
