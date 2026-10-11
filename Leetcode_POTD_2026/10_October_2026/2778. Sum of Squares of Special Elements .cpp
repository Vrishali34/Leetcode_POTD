```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int elem_total = nums.size();
        int square_sum = 0;
        for (int pos_idx = 1; pos_idx <= elem_total; pos_idx++) {
            if (elem_total % pos_idx == 0)
                square_sum += nums[pos_idx - 1] * nums[pos_idx - 1];
        }
        return square_sum;
    }
};
```
