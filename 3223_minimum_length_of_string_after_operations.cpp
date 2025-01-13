#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int minimumLength(string x) {
        unordered_map<char, int> z;
        for (char y : x) z[y]++;
        int d = 0;
        for (auto& p : z) d += p.second > 2 ? p.second - (p.second % 2 ? 1 : 2) : 0;
        return x.size() - d;
    }
};
