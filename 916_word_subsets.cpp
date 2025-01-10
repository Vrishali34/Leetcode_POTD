class Solution {
public:
    array<int, 26> freqMap(string t) {
        array<int, 26> f = {0};
        for (auto e : t) f[e - 'a']++;
        return f;
    }
    vector<string> wordSubsets(vector<string>& a, vector<string>& b) {
        array<int, 26> limit = {0};
        for (auto& d : b) {
            auto g = freqMap(d);
            for (int i = 0; i < 26; i++) limit[i] = max(limit[i], g[i]);
        }
        vector<string> o;
        for (auto& x : a) {
            auto g = freqMap(x);
            bool ok = true;
            for (int i = 0; i < 26 && ok; i++) if (limit[i] > g[i]) ok = false;
            if (ok) o.push_back(x);
        }
        return o;
    }
};
