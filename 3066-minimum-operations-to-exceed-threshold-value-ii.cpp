class Solution { 
public: 
    int minOperations(vector<int>& o, int w) { 
        priority_queue<long, vector<long>, greater<long>> j(o.begin(), o.end()); 
        int x = 0;
        while (j.top() < w) { 
            j.push(j.top() * 2 + (j.pop(), j.top())); 
            j.pop(); 
            x++; 
        } 
        return x; 
    }
};
