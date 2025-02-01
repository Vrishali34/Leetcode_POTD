class Solution {
public:
    bool isArraySpecial(vector<int>& x) {
        for (int y = 0; y < x.size() - 1; y++)
            if (x[y] % 2 == x[y + 1] % 2) return false;
        return true;
    }
};
