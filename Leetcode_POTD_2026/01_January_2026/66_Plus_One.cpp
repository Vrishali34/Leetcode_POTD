class Solution {
public:
    vector<int> plusOne(vector<int>& val_arr) {
        for (int idx = val_arr.size() - 1; idx >= 0; --idx) {
            if (val_arr[idx] < 9) {
                val_arr[idx]++;
                return val_arr;
            }
            val_arr[idx] = 0;
        }
        val_arr.insert(val_arr.begin(), 1);
        return val_arr;
    }
};
