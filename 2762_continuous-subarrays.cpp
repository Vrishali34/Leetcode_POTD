class Solution { 
public: 
    long long continuousSubarrays(vector<int>& w) { 
        int z=w.size(), x=0, y=0; 
        long long s=0; 
        multiset<int> k; 
        while(y<z) { 
            k.insert(w[y++]); 
            while(*prev(k.end())-*k.begin()>2) 
                k.erase(k.find(w[x++])); 
            s+=y-x; 
        } 
        return s; 
    } 
};
