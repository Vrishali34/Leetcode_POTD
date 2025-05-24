class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> h;
        for (int i = 0; i < words.size(); ++i) {
            bool d = false;
            for (char c : words[i]) {
                if (c == x) {
                    d = true;
                    break;
                }
            }
            if (d) {
                h.push_back(i);
            }
        }
        return h;
    }
};
