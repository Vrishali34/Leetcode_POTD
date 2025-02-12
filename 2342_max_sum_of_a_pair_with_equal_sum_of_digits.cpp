class Solution {
public:
    int zyx(int n) {
        int a = 0;
        while(n) {
            a += n % 10;
            n /= 10;
        }
        return a;
    }
    
    int maximumSum(vector<int>& v) {
        int res = -1, z[82] = {};
        for(int b : v) {
            int c = zyx(b);
            if(z[c]) res = max(res, z[c] + b);
            z[c] = max(z[c], b);
        }
        return res;
    }
};
