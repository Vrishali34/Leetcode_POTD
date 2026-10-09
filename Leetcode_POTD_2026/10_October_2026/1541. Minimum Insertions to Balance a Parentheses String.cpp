class Solution {
public:
    int minInsertions(string s) {
        int str_len = s.size();
        int pos_idx = 0, open_pending = 0, insert_cnt = 0;

        while (pos_idx < str_len) {
            if (s[pos_idx] == '(') {
                open_pending++;
                pos_idx++;
            } else {
                if (pos_idx + 1 < str_len && s[pos_idx + 1] == ')') {
                    pos_idx += 2;
                    if (open_pending > 0) open_pending--;
                    else insert_cnt++;
                } else {
                    pos_idx += 1;
                    insert_cnt++;
                    if (open_pending > 0) open_pending--;
                    else insert_cnt++;
                }
            }
        }

        insert_cnt += open_pending * 2;
        return insert_cnt;
    }
};
