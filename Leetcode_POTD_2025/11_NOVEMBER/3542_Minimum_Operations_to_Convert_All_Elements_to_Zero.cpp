class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans=0, t=0;
        vector<int> lvl(nums.size()+1);
        for(int x:nums){
            while(lvl[t]>x) --t,++ans;
            if(lvl[t]!=x) lvl[++t]=x;
        }
        return ans+t;
    }
};
