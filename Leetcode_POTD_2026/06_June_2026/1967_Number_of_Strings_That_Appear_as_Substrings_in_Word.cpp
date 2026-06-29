class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int match_cnt = 0;
        for (const string& curr_str : patterns) {
            if (word.find(curr_str) != string::npos) {
                match_cnt++;
            }
        }
        return match_cnt;
    }
};
