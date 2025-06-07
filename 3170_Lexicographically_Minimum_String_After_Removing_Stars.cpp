class Solution {
public:
    string clearStars(string s) {
        priority_queue<char, vector<char>, greater<char>> chMinHeap;
        vector<int> chIdx[26];
        vector<bool> keep(s.size(), true);

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '*') {
                int targetIdx = chIdx[chMinHeap.top() - 'a'].back();
                chIdx[chMinHeap.top() - 'a'].pop_back();
                chMinHeap.pop();
                keep[i] = false;
                keep[targetIdx] = false;
            } else {
                chMinHeap.push(s[i]);
                chIdx[s[i] - 'a'].push_back(i);
            }
        }
        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            if (keep[i]) res += s[i];
        }
        return res;
    }
};
