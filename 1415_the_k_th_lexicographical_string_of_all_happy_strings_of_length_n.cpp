class Solution { 
public:
    string getHappyString(int n, int k) {
        int u=0; string p, v;
        function<bool(string,int)> w=[&](string x,int y){
            if(x.size()==n) return ++u==k ? p=x,1 : 0;
            for(int i=0;i<3;i++) if(y!=i && w(x+char(97+i),i)) return 1;
            return 0;
        };
        return w(v,-1) ? p : "";
    }
};
