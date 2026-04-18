class Solution {
public:
    int mirrorDistance(int num_val) {
        int rev_val=0,orig=num_val;
        while(num_val){rev_val=rev_val*10+num_val%10;num_val/=10;}
        return abs(orig-rev_val);
    }
};
