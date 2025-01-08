class Solution {  
public:  
    int qx(const string& a, const string& b) {  
        int m = a.size(), n = b.size();  
        return m <= n && b.substr(0, m) == a && b.substr(n - m) == a;  
    }  
    int countPrefixSuffixPairs(vector<string>& z) {  
        int v = z.size(), c = 0;  
        for (int i = 0; i < v; ++i)  
            for (int j = i + 1; j < v; ++j)  
                c += qx(z[i], z[j]);  
        return c;  
    }  
};  
