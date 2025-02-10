class Solution {
public:
    string clearDigits(string x) {
        stack<char> y;
        for(char z : x) if(isdigit(z)) { if(y.size()) y.pop(); } else y.push(z);
        string w = "";
        while(y.size()) w = y.top() + w, y.pop();
        return w;
    }
};
