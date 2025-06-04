class Solution {
public:
    string answerString(string x, int y) {
        if (y == 1) return x;
        string a;
        for (int j = 0; j < x.size(); ++j)
            a = max(a, x.substr(j, x.size() - y + 1));
        return a;
    }
};
