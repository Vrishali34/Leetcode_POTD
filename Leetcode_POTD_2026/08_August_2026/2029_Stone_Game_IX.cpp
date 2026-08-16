class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int remZero = 0, remOne = 0, remTwo = 0;
        for (int val : stones) {
            int r = val % 3;
            if (r == 0) remZero++;
            else if (r == 1) remOne++;
            else remTwo++;
        }
        if (remZero % 2 == 0) return remOne > 0 && remTwo > 0;
        return abs(remOne - remTwo) >= 3;
    }
};
