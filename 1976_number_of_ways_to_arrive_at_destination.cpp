class Solution {
public:
    int countPaths(int z, vector<vector<int>>& q) {
        vector<vector<pair<int,int>>> r(z);
        for(auto& y : q) r[y[0]].emplace_back(y[1],y[2]), r[y[1]].emplace_back(y[0],y[2]);
        priority_queue<pair<long,long>,vector<pair<long,long>>,greater<>> p;
        vector<long> a(z,1e18),b(z); a[0]=0,b[0]=1,p.emplace(0,0);
        while(p.size()){
            auto [t,x]=p.top();p.pop();
            if(t>a[x])continue;
            for(auto&[j,k]:r[x]){
                long u=t+k;
                if(u<a[j])a[j]=u,b[j]=b[x],p.emplace(u,j);
                else if(u==a[j])b[j]=(b[j]+b[x])%1000000007;
            }
        }
        return b[z-1];
    }
};
