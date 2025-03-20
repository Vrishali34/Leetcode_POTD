#include <vector>
#include <numeric>
using namespace std;
struct B {
    vector<int> p, r, w;
    B(int n) : p(n), r(n), w(n, (1 << 17) - 1) { iota(p.begin(), p.end(), 0); }
    int f(int x) { return p[x] == x ? x : p[x] = f(p[x]); }
    void u(int x, int y, int z) { 
        int a = f(x), b = f(y), v = w[a] & w[b] & z;
        if (a != b) (r[a] < r[b]) ? p[a] = b : (p[b] = a, r[a] += (r[a] == r[b]));
        w[a] = w[b] = v;
    }
    int q(int x, int y) { return f(x) == f(y) ? w[f(x)] : -1; }
};
struct Solution {
    vector<int> minimumCost(int n, vector<vector<int>>& e, vector<vector<int>>& q) {
        B d(n); vector<int> a;
        for (auto& v : e) d.u(v[0], v[1], v[2]);
        for (auto& v : q) a.push_back(d.q(v[0], v[1]));
        return a;
    }
};
