class Solution {
public:
    bool isCircularSentence(string& s) {
        return s.front() == s.back() && all_of(s.begin(), s.end(), [&, i=1](char) mutable {
            return s[i++] != ' ' || s[i-2] == s[i];
        });
    }
};
