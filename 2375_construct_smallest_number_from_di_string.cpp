#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string smallestNumber(string f) {
        string g;
        int h = f.length();
        vector<int> i(h, 0); 
        i[h - 1] = (f[h - 1] == 'D') ? 1 : 0;
        for (int j = h - 2; j >= 0; --j) 
            if (f[j] == 'D') i[j] = i[j + 1] + 1;
        int k = 1;
        for (int j = 0; j < h; ++j) {
            int l = i[j] + k;
            if (l == k) k = j + 2;
            g += to_string(l);
        }
        return g + to_string(k);
    }
};
