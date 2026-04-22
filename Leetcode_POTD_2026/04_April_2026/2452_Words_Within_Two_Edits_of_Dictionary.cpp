class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> hit_list;
        for (const string& q_str : queries) {
            for (const string& d_str : dictionary) {
                int mismatch_count = 0;
                for (int i = 0; i < q_str.size(); ++i) {
                    if (q_str[i] != d_str[i]) mismatch_count++;
                    if (mismatch_count > 2) break;
                }
                if (mismatch_count <= 2) {
                    hit_list.push_back(q_str);
                    break;
                }
            }
        }
        return hit_list;
    }
};
