class Solution {
public:
    int getCommon(vector<int>& num_list_1, vector<int>& num_list_2) {
        int idx_num_1 = 0;
        int idx_num_2 = 0;
        int size_num_1 = num_list_1.size();
        int size_num_2 = num_list_2.size();
        while (idx_num_1 < size_num_1 && idx_num_2 < size_num_2) {
            if (num_list_1[idx_num_1] == num_list_2[idx_num_2]) {
                return num_list_1[idx_num_1];
            }
            if (num_list_1[idx_num_1] < num_list_2[idx_num_2]) {
                idx_num_1++;
            } else {
                idx_num_2++;
            }
        }
        return -1;
    }
};
