class Solution {
public:
    vector<string> stringMatching(vector<string>& x) {
        vector<string> y;
        int z = x.size();
        for (int a = 0; a < z; ++a)
            for (int b = 0; b < z; ++b)
                if (a != b && x[b].find(x[a]) != string::npos) {
                    y.push_back(x[a]);
                    break;
                }
        return y;
    }
};
