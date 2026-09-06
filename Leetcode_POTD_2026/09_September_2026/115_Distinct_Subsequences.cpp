class Solution {
public:
    int numDistinct(string s, string t) {
        int len_s = s.size(), len_t = t.size();
        vector<vector<unsigned long long>> way_count(len_s + 1, vector<unsigned long long>(len_t + 1, 0));
        for (int i = 0; i <= len_s; i++) way_count[i][0] = 1;

        for (int i = 1; i <= len_s; i++) {
            for (int j = 1; j <= len_t; j++) {
                way_count[i][j] = way_count[i - 1][j];
                if (s[i - 1] == t[j - 1])
                    way_count[i][j] += way_count[i - 1][j - 1];
            }
        }
        return (int)way_count[len_s][len_t];
    }
};
