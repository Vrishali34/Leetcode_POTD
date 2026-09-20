class Solution {
public:
    int reverseDegree(string s) {
        int degree_sum = 0;
        for (int pos_idx = 0; pos_idx < s.size(); pos_idx++) {
            int rev_val = 26 - (s[pos_idx] - 'a');
            degree_sum += rev_val * (pos_idx + 1);
        }
        return degree_sum;
    }
};
