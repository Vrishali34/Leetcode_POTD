class Solution {
public:
    int minElement(vector<int>& nums) {
        int least_sum = 37;
        for (int entry : nums) {
            int digit_total = 0;
            while (entry > 0) {
                digit_total += entry % 10;
                entry /= 10;
            }
            least_sum = min(least_sum, digit_total);
        }
        return least_sum;
    }
};
