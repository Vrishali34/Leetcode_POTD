class Solution {
public:
    string findDifferentBinaryString(vector<string>& bit_pool) {
        string unique_seq = "";
        for (int idx = 0; idx < bit_pool.size(); ++idx) {
            unique_seq += (bit_pool[idx][idx] == '0' ? '1' : '0');
        }
        return unique_seq;
    }
};
