class Solution {
public:
    string decodeCiphertext(string encoded_txt, int row_cnt) {
        int total_sz = encoded_txt.size();
        int col_cnt = total_sz / row_cnt;
        string raw_msg = "";
        for (int start_c = 0; start_c < col_cnt; ++start_c) {
            for (int r = 0, c = start_c; r < row_cnt && c < col_cnt; ++r, ++c) {
                raw_msg += encoded_txt[r * col_cnt + c];
            }
        }
        while (!raw_msg.empty() && raw_msg.back() == ' ') raw_msg.pop_back();
        return raw_msg;
    }
};
