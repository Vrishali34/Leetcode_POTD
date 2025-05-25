class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int cnts[26][26] = {0};
        for (const auto& w : words) {
            cnts[w[0] - 'a'][w[1] - 'a']++;
        }

        int jwl = 0;
        bool bll = false;

        for (int i = 0; i < 26; ++i) {
            jwl += (cnts[i][i] / 2) * 4;
            if (cnts[i][i] % 2 == 1) {
                bll = true;
            }
            for (int j = i + 1; j < 26; ++j) {
                jwl += std::min(cnts[i][j], cnts[j][i]) * 4;
            }
        }
        return jwl + (bll ? 2 : 0);
    }
};
