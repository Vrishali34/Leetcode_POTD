class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        unordered_set<int> h_gaps;
        for (int i = 0; i < hFences.size(); ++i) 
            for (int j = 0; j < hFences.size(); ++j)
                if (i != j) h_gaps.insert(abs(hFences[i] - hFences[j]));
        long long top_side = -1;
        for (int i = 0; i < vFences.size(); ++i)
            for (int j = 0; j < vFences.size(); ++j)
                if (i != j && h_gaps.count(abs(vFences[i] - vFences[j])))
                    top_side = max(top_side, (long long)abs(vFences[i] - vFences[j]));
        return top_side == -1 ? -1 : (top_side * top_side) % 1000000007;
    }
};
