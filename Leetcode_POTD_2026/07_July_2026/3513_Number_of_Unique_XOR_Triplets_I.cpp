class Solution {
public:
    int uniqueXorTriplets(vector<int>& num_vec) {
        int seq_len = num_vec.size();
        if (seq_len <= 2) return seq_len;
        return 1 << (32 - __builtin_clz(seq_len));
    }
};
