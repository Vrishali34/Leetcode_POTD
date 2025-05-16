class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& X, vector<int>& Y) {
        int n=X.size(),z=0; vector<int> T(n,1),P(n);
        iota(P.begin(),P.end(),0);
        for(int i=0;i<n;++i) for(int j=0;j<i;++j)
            if(Y[i]^Y[j] && X[i].size()==X[j].size() && f(X[i],X[j])==1 && T[j]+1>T[i])
                T[i]=T[j]+1,P[i]=j;
        for(int i=0;i<n;++i) if(T[i]>T[z]) z=i;
        vector<string> R; while(P[z]!=z) R.push_back(X[z]),z=P[z];
        R.push_back(X[z]); reverse(R.begin(),R.end()); return R;
    }
    int f(string&a,string&b){int r=0;for(int i=0;i<a.size();++i)r+=a[i]!=b[i];return r;}
};
