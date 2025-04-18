class Solution {
public:
    string countAndSay(int n) {
        string w="1";
        while(--n){
            string x;
            for(int a=0;a<w.size();){
                int b=a;
                while(b<w.size()&&w[a]==w[b])++b;
                x+=to_string(b-a)+w[a];
                a=b;
            }
            w=x;
        }
        return w;
    }
};
