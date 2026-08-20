class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr_first, arr_second;
        arr_first.push_back(nums[0]);
        arr_second.push_back(nums[1]);

        for (int idx = 2; idx < (int)nums.size(); idx++) {
            if (arr_first.back() > arr_second.back())
                arr_first.push_back(nums[idx]);
            else
                arr_second.push_back(nums[idx]);
        }

        arr_first.insert(arr_first.end(), arr_second.begin(), arr_second.end());
        return arr_first;
    }
};
