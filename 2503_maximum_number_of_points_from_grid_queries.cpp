class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& m, vector<int>& q) {
        int h=m.size(),w=m[0].size(),f[]{1,0,-1,0,1};
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> u;
        vector v(h, vector<bool>(w)); u.emplace(m[0][0],0,0); v[0][0]=1;
        int z=0,n=q.size(); vector<int> res(n),p(n);
        iota(p.begin(),p.end(),0);
        sort(p.begin(),p.end(),[&](int i,int j){return q[i]<q[j];});
        for(int i:p){
            while(!u.empty()&&get<0>(u.top())<q[i]){
                auto [a,b,c]=u.top(); u.pop(); z++;
                for(int k=0;k<4;k++){
                    int r=b+f[k],s=c+f[k+1];
                    if(r>=0&&s>=0&&r<h&&s<w&&!v[r][s]){
                        v[r][s]=1; u.emplace(m[r][s],r,s);
                    }
                }
            }
            res[i]=z;
        }
        return res;
    }
};
