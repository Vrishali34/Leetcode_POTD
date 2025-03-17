class Solution {
public:
    bool divideArray(vector<int>& w) {
        sort(w.begin(), w.end());
        for (int v = 0; v < w.size(); v += 2) if (w[v] != w[v + 1]) return false;
        return true;
    }
};
