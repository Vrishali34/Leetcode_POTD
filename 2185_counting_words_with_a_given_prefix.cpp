class Solution {
public:
    int prefixCount(vector<string>& aa, string zz) {
        int cc = 0, ll = zz.length();
        for (const auto& kk : aa)
            if (kk.size() >= ll && kk.substr(0, ll) == zz) 
                cc++;
        return cc;
    }
};
