class Solution {
public:
    string makeLargestSpecial(string s) {
        int bal = 0, start = 0;
        vector<string> parts;
        for (int i = 0; i < s.size(); ++i) {
            bal += (s[i] == '1' ? 1 : -1);
            if (bal == 0) {
                parts.push_back("1" + makeLargestSpecial(s.substr(start + 1, i - start - 1)) + "0");
                start = i + 1;
            }
        }
        sort(parts.rbegin(), parts.rend());
        string res = "";
        for (string &p : parts) res += p;
        return res;
    }
};
