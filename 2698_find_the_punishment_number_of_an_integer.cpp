class Solution {
public:
    int punishmentNumber(int n) {
        int z=0;
        for(int i=1;i<=n;i++) {
            std::string s = std::to_string(i*i);
            if(h(s,0,i,0)) z+=i*i;
        }
        return z;
    }
private:
    bool h(const std::string &s, int x, int y, int c) {
        if(x==s.size()) return c==y;
        int p=0;
        for(int i=x;i<s.size();i++) {
            p=p*10+(s[i]-'0');
            if(c+p>y) break;
            if(h(s,i+1,y,c+p)) return true;
        }
        return false;
    }
};
