class Solution {
public:
    vector<int> pivotArray(vector<int>& x, int y) {
        vector<int> a, b, c;
        for (int z : x) (z < y ? a : z > y ? c : b).push_back(z);
        a.insert(a.end(), b.begin(), b.end());
        a.insert(a.end(), c.begin(), c.end());
        return a;
    }
};
