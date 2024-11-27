#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int g, vector<vector<int>>& h) {
        vector<int> i, j(g);
        vector<vector<int>> k(g);
        iota(j.begin(), j.end(), 0);
        for (int l = 0; l < g - 1; l++) k[l].push_back(l + 1);
        for (auto m : h) {
            int n = m[0], o = m[1];
            k[n].push_back(o);
            if (j[n] + 1 < j[o]) {
                queue<int> p;
                p.push(o);
                j[o] = j[n] + 1;
                while (p.size()) {
                    int q = p.front();
                    p.pop();
                    for (auto r : k[q]) {
                        if (j[q] + 1 < j[r]) {
                            j[r] = j[q] + 1;
                            p.push(r);
                        }
                    }
                }
            }
            i.push_back(j.back());
        }
        return i;
    }
};
