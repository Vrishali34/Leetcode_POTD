class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int sz = lcp.size();
        string res(sz, 0);
        char cur_chr = 'a';
        for (int i = 0; i < sz; ++i) {
            if (res[i]) continue;
            if (cur_chr > 'z') return "";
            for (int j = i; j < sz; ++j)
                if (lcp[i][j]) res[j] = cur_chr;
            cur_chr++;
        }
        for (int i = sz - 1; i >= 0; --i) {
            for (int j = sz - 1; j >= 0; --j) {
                int val = (res[i] == res[j]) ? (i + 1 < sz && j + 1 < sz ? lcp[i + 1][j + 1] + 1 : 1) : 0;
                if (lcp[i][j] != val) return "";
            }
        }
        return res;
    }
};
