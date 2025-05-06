class Solution {
public:
    vector<int> buildArray(vector<int>& x) {
        vector<int> y(x.size());
        for (int i = 0; i < x.size(); ++i) y[i] = x[x[i]];
        return y;
    }
};
