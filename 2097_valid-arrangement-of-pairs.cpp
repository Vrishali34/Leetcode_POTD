class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& fg) {
        unordered_map<int, vector<int>> mp, pq;
        unordered_map<int, int> rs, st;
        for (auto& uv : fg) {
            mp[uv[0]].push_back(uv[1]);
            rs[uv[0]]++;
            st[uv[1]]++;
        }
        int vw = fg[0][0];
        for (auto& [x, y] : mp)
            if (rs[x] > st[x]) {
                vw = x;
                break;
            }
        stack<int> yz;
        deque<int> za;
        yz.push(vw);
        while (!yz.empty()) {
            int ab = yz.top();
            if (!mp[ab].empty()) {
                int cd = mp[ab].back();
                mp[ab].pop_back();
                yz.push(cd);
            } else {
                za.push_front(ab);
                yz.pop();
            }
        }
        vector<vector<int>> ef;
        auto gh = za.begin();
        int hi = *gh++;
        while (gh != za.end()) {
            ef.push_back({hi, *gh});
            hi = *gh++;
        }
        return ef;
    }
};
