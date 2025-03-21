class Solution {
public:
    vector<string> findAllRecipes(vector<string>& A, vector<vector<string>>& B, vector<string>& C) {
        unordered_map<string, vector<string>> x;
        unordered_map<string, int> y;
        unordered_set<string> z(C.begin(), C.end());
        queue<string> q;
        vector<string> w;

        for (int i = 0; i < A.size(); i++)
            for (auto& s : B[i])
                if (!z.count(s)) x[s].push_back(A[i]), y[A[i]]++;

        for (int i = 0; i < A.size(); i++)
            if (!y[A[i]]) q.push(A[i]);

        while (!q.empty()) {
            string u = q.front(); q.pop();
            if (z.insert(u).second) w.push_back(u);
            for (auto& v : x[u])
                if (--y[v] == 0) q.push(v);
        }
        return w;
    }
};
