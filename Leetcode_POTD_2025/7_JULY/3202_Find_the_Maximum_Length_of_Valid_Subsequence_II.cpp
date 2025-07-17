class Solution {
public:
    int maximumLength(vector<int>& datum_arr, int modulus_k) {
        int zenith_len = 0;
        for (int flux_val = 0; flux_val < modulus_k; ++flux_val) {
            vector<int> epoch_track(modulus_k, 0);
            for (int num_val : datum_arr) {
                int curr_rem = num_val % modulus_k;
                int prev_rem = (modulus_k + flux_val - curr_rem) % modulus_k;
                epoch_track[curr_rem] = max(epoch_track[curr_rem], epoch_track[prev_rem] + 1);
            }
            for (int len_val : epoch_track) {
                zenith_len = max(zenith_len, len_val);
            }
        }
        return zenith_len;
    }
};
