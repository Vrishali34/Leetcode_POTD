class Solution {
public:
    int countCompleteSubarrays(vector<int>& a) {
        int k = unordered_set<int>(a.begin(), a.end()).size(), y = 0;
        for (int i = 0; i < a.size(); ++i) {
            set<int> q;
            for (int j = i; j < a.size(); ++j) {
                q.insert(a[j]);
                if (q.size() == k) y++;
                if (q.size() > k) break;
            }
        }
        return y;
    }
};
