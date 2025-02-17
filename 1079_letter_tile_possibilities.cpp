#include <unordered_map>
#include <string>

class Solution {
public:
    int numTilePossibilities(std::string t) {
        std::unordered_map<char, int> f;
        for (char c : t) f[c]++;
        return dfs(f);
    }
    
private:
    int dfs(std::unordered_map<char, int>& f) {
        int s = 0;
        for (auto& p : f) {
            if (p.second) {
                p.second--;
                s += 1 + dfs(f);
                p.second++;
            }
        }
        return s;
    }
};
