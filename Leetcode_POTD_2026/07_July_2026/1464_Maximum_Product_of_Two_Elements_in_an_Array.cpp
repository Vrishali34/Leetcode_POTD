class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int peak_one = 0, peak_two = 0;
        for (int val_num : nums) {
            if (val_num > peak_one) {
                peak_two = peak_one;
                peak_one = val_num;
            } else if (val_num > peak_two) {
                peak_two = val_num;
            }
        }
        return (peak_one - 1) * (peak_two - 1);
    }
};
