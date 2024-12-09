class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& x, vector<vector<int>>& q) {
        int z = x.size();
        vector<int> p(z);
        for (int i = 1; i < z; i++) 
            p[i] = p[i - 1] + ((x[i] % 2) == (x[i - 1] % 2));
        vector<bool> r;
        for (auto& y : q) 
            r.push_back(p[y[1]] - (y[0] > 0 ? p[y[0]] : 0) == 0);
        return r;
    }
};
