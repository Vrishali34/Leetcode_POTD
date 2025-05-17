class Solution {
public:
    void sortColors(vector<int>& q) {
        int a=0,b=0,c=0;
        for(int p:q) p==0?a++:p==1?b++:c++;
        q.assign(a,0); q.insert(q.end(),b,1); q.insert(q.end(),c,2);
    }
};
