class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& arr) {
        unordered_map<string, int> hm;
        for (auto& a : arr) {
            string temp;
            for (int b : a) temp += to_string(b ^ a[0]);
            hm[temp]++;
        }
        int mx = 0;
        for (auto& val : hm) mx = max(mx, val.second);
        return mx;
    }
};
