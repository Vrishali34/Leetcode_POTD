class Solution {
public:
    int countTriples(int limit) {
        int triple_cnt=0;
        for(int a=1;a<=limit;a++)
            for(int b=1;b<=limit;b++){
                int sum_sq=a*a+b*b;
                int c=sqrt(sum_sq);
                if(c<=limit && c*c==sum_sq) triple_cnt++;
            }
        return triple_cnt;
    }
};
