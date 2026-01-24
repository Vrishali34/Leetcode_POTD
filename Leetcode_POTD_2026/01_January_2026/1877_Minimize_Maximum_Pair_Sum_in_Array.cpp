class Solution {
public:
    int minPairSum(vector<int>& vals) {
        sort(vals.begin(), vals.end());
        int top_sum = 0, len = vals.size();
        for (int i = 0; i < len / 2; ++i) {
            top_sum = max(top_sum, vals[i] + vals[len - 1 - i]);
        }
        return top_sum;
    }
};
