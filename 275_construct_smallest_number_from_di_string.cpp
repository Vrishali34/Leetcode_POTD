class Solution {
public:
    string smallestNumber(string x) {
        string y;
        int z = x.size(), a[z];
        a[z - 1] = (x[z - 1] == 'D') ? 1 : 0;
        for (int i = z - 2; i >= 0; --i) 
            if (x[i] == 'D') a[i] = a[i + 1] + 1;
        int b = 1;
        for (int i = 0; i < z; ++i) {
            int c = a[i] + b;
            if (c == b) b = i + 2;
            y += to_string(c);
        }
        return y + to_string(b);
    }
};
