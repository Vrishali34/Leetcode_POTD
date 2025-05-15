class Solution {
public:
vector<string> getLongestSubsequence(vector<string>& b, vector<int>& u) {
    vector<string> w;
    for (int e = 0, j = -1; e < b.size(); e++)
        if (j == -1 || u[e] != u[j]) w.push_back(b[e]), j = e;
    return w;
}
};
