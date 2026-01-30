class Solution {
public:
    long long minimumCost(string s, string t, vector<string>& a, vector<string>& b, vector<int>& w) {
        unordered_map<string,int> map_idx;
        int idx=0;
        for(auto& x:a) if(!map_idx.count(x)) map_idx[x]=idx++;
        for(auto& x:b) if(!map_idx.count(x)) map_idx[x]=idx++;

        vector<vector<pair<int,int>>> adj(idx);
        for(int i=0;i<a.size();i++)
            adj[map_idx[a[i]]].push_back({map_idx[b[i]], w[i]});

        const long long inf=4e18;
        vector<vector<long long>> best(idx, vector<long long>(idx, inf));

        for(int i=0;i<idx;i++){
            priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
            pq.push({0,i});
            best[i][i]=0;
            while(!pq.empty()){
                auto [c,u]=pq.top(); pq.pop();
                if(c>best[i][u]) continue;
                for(auto& [v,w]:adj[u])
                    if(best[i][v]>c+w){
                        best[i][v]=c+w;
                        pq.push({best[i][v],v});
                    }
            }
        }

        int n=s.size();
        vector<long long> dp(n+1,inf);
        dp[0]=0;

        unordered_set<int> lens;
        for(auto& x:a) lens.insert(x.size());

        for(int i=0;i<n;i++){
            if(dp[i]==inf) continue;
            if(s[i]==t[i]) dp[i+1]=min(dp[i+1],dp[i]);
            for(int l:lens){
                if(i+l>n) continue;
                string x=s.substr(i,l), y=t.substr(i,l);
                if(x==y) dp[i+l]=min(dp[i+l],dp[i]);
                else if(map_idx.count(x)&&map_idx.count(y))
                    dp[i+l]=min(dp[i+l],dp[i]+best[map_idx[x]][map_idx[y]]);
            }
        }
        return dp[n]>=inf?-1:dp[n];
    }
};
