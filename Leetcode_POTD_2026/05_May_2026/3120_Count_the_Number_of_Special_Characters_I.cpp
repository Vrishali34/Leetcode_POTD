class Solution {
public:
    int numberOfSpecialChars(string word) {
        long long low_bits = 0, up_bits = 0;
        for (char ch : word) {
            if (ch >= 'a' && ch <= 'z') low_bits |= (1LL << (ch - 'a'));
            else if (ch >= 'A' && ch <= 'Z') up_bits |= (1LL << (ch - 'A'));
        }
        return __builtin_popcountll(low_bits & up_bits);
    }
};
