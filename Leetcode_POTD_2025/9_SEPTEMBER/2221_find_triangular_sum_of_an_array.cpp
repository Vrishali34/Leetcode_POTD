class Solution {
public:
    int triangularSum(vector<int>& num_list) {
        int N = num_list.size();
        while (N > 1) {
            for (int i = 0; i < N - 1; ++i) {
                num_list[i] = (num_list[i] + num_list[i + 1]) % 10;
            }
            N--;
        }
        return num_list[0];
    }
};
