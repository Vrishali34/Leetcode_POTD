class Solution {
public:
    bool checkIfExist(vector<int>& b) {
        bitset<1001> d[2] = {0};
        for (int v : b) {
            int u = abs(v);
            if ((u <= 500 && d[v < 0][2 * u]) || (u % 2 == 0 && d[v < 0][u / 2]))
                return 1;
            d[v < 0][u] = 1;
        }
        return 0;
    }
};
