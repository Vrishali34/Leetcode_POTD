class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M=1e9+7, L=100000;
        vector<long long> pre(L+1), suf(L+1);
        for(int x:nums) suf[x]++;
        long long ans=0;
        for(int j=0;j<nums.size();j++){
            int mid=nums[j], dbl=mid*2;
            suf[mid]--;
            if(dbl<=L) ans=(ans + pre[dbl]*suf[dbl])%M;
            pre[mid]++;
        }
        return ans;
    }
};
