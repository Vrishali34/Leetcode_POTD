class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto bit_map = [](int val_a, int val_b) {
            int cnt_a = __builtin_popcount(val_a);
            int cnt_b = __builtin_popcount(val_b);
            return cnt_a == cnt_b ? val_a < val_b : cnt_a < cnt_b;
        };
        sort(arr.begin(), arr.end(), bit_map);
        return arr;
    }
};
