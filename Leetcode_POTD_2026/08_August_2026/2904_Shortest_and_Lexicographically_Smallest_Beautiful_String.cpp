class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int str_len = s.size();
        string best_sub = "";
        for (int start_idx = 0; start_idx < str_len; start_idx++) {
            int one_count = 0;
            for (int end_idx = start_idx; end_idx < str_len; end_idx++) {
                if (s[end_idx] == '1') one_count++;
                if (one_count == k) {
                    string cand_sub = s.substr(start_idx, end_idx - start_idx + 1);
                    if (best_sub.empty() || cand_sub.size() < best_sub.size() ||
                        (cand_sub.size() == best_sub.size() && cand_sub < best_sub))
                        best_sub = cand_sub;
                    break;
                }
            }
        }
        return best_sub;
    }
};
