class Solution {
public:
    int numRabbits(vector<int>& qz) {
        map<int, int> o;
        int p = 0;
        for (int x : qz) {
            if (!o[x] || o[x] % (x + 1) == 0) p += x + 1;
            o[x]++;
        }
        return p;
    }
};
