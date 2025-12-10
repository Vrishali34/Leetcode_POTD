class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size(),mod=1e9+7;
        for(int i=1;i<n;i++) if(complexity[i]<=complexity[0]) return 0;
        long long fact_val=1;
        for(int i=2;i<n;i++) fact_val=fact_val*i%mod;
        return fact_val;
    }
};
