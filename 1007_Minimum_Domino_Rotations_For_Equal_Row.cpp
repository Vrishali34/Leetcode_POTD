class Solution {
public:
    int minDominoRotations(vector<int>& p, vector<int>& q) {
        for (int z : {p[0], q[0]}) {
            int i = 0, x = 0, y = 0;
            for (; i < p.size(); ++i) {
                if (p[i] != z && q[i] != z) break;
                x += p[i] != z;
                y += q[i] != z;
            }
            if (i == p.size()) return min(x, y);
        }
        return -1;
    }
};
