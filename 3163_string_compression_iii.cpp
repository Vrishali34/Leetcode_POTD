class Solution { 
public:
    static string compressedString(string& s) {
        int len=s.size(), i=0;
        string out;
        out.reserve(len);
        for(int j=0; j<len; ) {
            while(j<len && s[j]==s[i]) j++;
            auto [parts, left]=div(j-i, 9);
            for(int k=0; k<parts; k++) {
                out+='9';
                out+=s[i];
            }
            if(left>0) {
                out+=left+'0';
                out+=s[i];
            }
            i=j;
        }
        return out;
    }
};
