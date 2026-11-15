class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int even_cnt = 1, odd_cnt = 0, pre_par = 0, total = 0;
        for (int val : arr) {
            pre_par ^= (val & 1);
            total = (total + (pre_par ? even_cnt : odd_cnt)) % MOD;
            pre_par ? odd_cnt++ : even_cnt++;
        }
        return total;
    }
};
