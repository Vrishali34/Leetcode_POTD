class Solution {
public:
    int maxChunksToSorted(vector<int>& v) {
        int w = 0, x = 0;
        for (int y = 0; y < v.size(); y++) {
            x += v[y] - y;
            w += (x == 0);
        }
        return w;
    }
};
