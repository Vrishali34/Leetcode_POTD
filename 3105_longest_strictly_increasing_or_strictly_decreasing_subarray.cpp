class Solution {
public:
    int longestMonotonicSubarray(vector<int>& X) {
        int top = 1, up = 1, down = 1;
        for (int j = 1; j < X.size(); ++j) {
            if (X[j] > X[j - 1]) up++, down = 1;
            else if (X[j] < X[j - 1]) down++, up = 1;
            else up = down = 1;
            top = max(top, max(up, down));
        }
        return top;
    }
};
