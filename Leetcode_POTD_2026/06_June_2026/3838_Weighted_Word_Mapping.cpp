class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string mapped_str = "";
        for (const string& txt_item : words) {
            int net_wt = 0;
            for (char alph_chr : txt_item) {
                net_wt += weights[alph_chr - 'a'];
            }
            mapped_str += ('z' - (net_wt % 26));
        }
        return mapped_str;
    }
};
