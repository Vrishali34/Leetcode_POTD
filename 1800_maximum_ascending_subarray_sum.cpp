class Solution {
public:
    int maxAscendingSum(vector<int>& x) {
        int f = x.size(), y = 0, t = x[0];
        for(int i = 1; i < f; i++) {
            if(x[i] > x[i-1]) t += x[i];
            else y = max(y, t), t = x[i];
        }
        return max(y, t);
    }
};
