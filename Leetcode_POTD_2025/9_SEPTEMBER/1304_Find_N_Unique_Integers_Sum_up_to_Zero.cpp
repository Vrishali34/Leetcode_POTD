class Solution {
public:
    std::vector<int> sumZero(int n) {
        std::vector<int> result_arr;
        if (n % 2 != 0) {
            result_arr.push_back(0);
        }
        for (int i = 1; i <= n / 2; ++i) {
            result_arr.push_back(i);
            result_arr.push_back(-i);
        }
        return result_arr;
    }
};
