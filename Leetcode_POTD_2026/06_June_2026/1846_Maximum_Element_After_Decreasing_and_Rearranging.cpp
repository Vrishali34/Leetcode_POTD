class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int top_val = 0;
        for (int curr_num : arr) {
            top_val = min(top_val + 1, curr_num);
        }
        return top_val;
    }
};
