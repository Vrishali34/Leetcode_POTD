class Solution {
public:
    int minSubarray(vector<int>& a, int p) {
        long s=0; for(long x:a) s+=x;
        long r=s%p; if(!r) return 0;
        unordered_map<long,int> mp; mp[0]=-1;
        long cur=0; int ans=1e9;
        for(int i=0;i<a.size();i++){
            cur=(cur+a[i])%p;
            long want=(cur-r+p)%p;
            if(mp.count(want)) ans=min(ans,i-mp[want]);
            mp[cur]=i;
        }
        return ans==1e9||ans==a.size()?-1:ans;
    }
};
