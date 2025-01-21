class Solution {  
public:  
    long long gridGame(vector<vector<int>>& g) {  
        int n = g[0].size();  
        vector<long long> p1(n + 1), p2(n + 1);  
        for (int i = 0; i < n; ++i) {  
            p1[i + 1] = p1[i] + g[0][i];  
            p2[i + 1] = p2[i] + g[1][i];  
        }  
        long long mn = LLONG_MAX;  
        for (int i = 0; i < n; ++i)  
            mn = min(mn, max(p1[n] - p1[i + 1], p2[i]));  
        return mn;  
    }  
};  
