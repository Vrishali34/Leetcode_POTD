class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> k(n);
        for(auto& p : edges)
            k[p[1]]++;
        int v = -1, g = 0;
        for(int i = 0; i < n; ++i) {
            if(!k[i]) {
                g++;
                v = i;
            }
            if(g > 1) return -1;
        }
        return v;
    }
};
