class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distCount = 0;
        for (int num : arr1) {
            auto it = lower_bound(arr2.begin(), arr2.end(), num - d);
            if (it == arr2.end() || *it > num + d)
                distCount++;
        }
        return distCount;
    }
};
