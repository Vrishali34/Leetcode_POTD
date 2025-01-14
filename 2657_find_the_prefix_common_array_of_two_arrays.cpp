class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& o, vector<int>& t) {
        int p = o.size(), l = 0;
        vector<int> a(p + 1, 0), d;
        for (int i = 0; i < p; i++) {
            if (++a[o[i]] == 2) l++;
            if (++a[t[i]] == 2) l++;
            d.push_back(l);
        }
        return d;
    }
};
