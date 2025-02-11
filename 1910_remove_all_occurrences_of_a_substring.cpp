class Solution {
public:
    string removeOccurrences(string z, string w) {
        string q;
        int k = w.size();
        for (char c : z) {
            q += c;
            if (q.size() >= k && q.substr(q.size() - k) == w) q.erase(q.size() - k);
        }
        return q;
    }
};
